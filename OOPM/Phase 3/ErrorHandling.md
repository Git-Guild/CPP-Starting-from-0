# C++ Error Handling Reference Guide

## Table of Contents
* [1. Overview of Exception Handling](#1-overview-of-exception-handling)
* [2. Common Error Codes & Scenarios](#2-common-error-codes--scenarios)
* [3. Standard Exception Hierarchy Mapping](#3-standard-exception-hierarchy-mapping)
* [4. Best Practices](#4-best-practices)

---

## 1. Overview of Exception Handling
C++ manages runtime errors using three core keywords to separate error-detection from error-handling logic:

* **`try`**: Defines a code block scope where exceptions might be thrown.
* **`throw`**: Signals that an error or specific status code has occurred, halting normal execution.
* **`catch`**: Intercepts and handles the thrown exception based on its data type or class hierarchy.

### Basic Workflow Template
```cpp
try {
    // Code that might fail
    if (error_condition) {
        throw std::runtime_error("Critical execution failure");
    }
} 
catch (const std::exception& e) {
    // Graceful error recovery or logging
    std::cerr << "Error: " << e.what() << std::endl;
}
```

---

## 2. Common Error Codes & Scenarios

* **Division by Zero (`const char*`)**
  * *Scenario*: Triggered when a denominator evaluates to `0`.
  * *Purpose*: Prevents invalid mathematical operations and hardware-level faults.
* **Error 404 (Not Found / `int`)**
  * *Scenario*: Used when a requested file, resource, index, or database element does not exist.
* **Error 403 (Forbidden / `int`)**
  * *Scenario*: Signifies that the current user or process lacks required access permissions.
* **Error 402 (Payment Required / Custom Class)**
  * *Scenario*: Mapped via custom domain models (e.g., `InsufficientFundsException`).
  * *Purpose*: Enforces business rule constraints when financial limits are breached.
* **`std::bad_alloc`**
  * *Scenario*: Automatically thrown when dynamic memory allocation via `new` fails.
  * *Root Cause*: Insufficient system RAM or memory fragmentation.

---

## 3. Standard Exception Hierarchy Mapping
All standard C++ exceptions stem from a unified hierarchy, allowing you to catch errors broadly or specifically.

### Universal Base Class
* **`std::exception`**: The universal parent class for all standard C++ runtime exceptions. Provides the virtual `.what()` method for error messages.

### Logic Errors (`std::logic_error`)
*Derived from `std::exception`. These represent preventable bugs that could be avoided through better code logic.*
* **`std::out_of_range`**: Out-of-bounds container access (e.g., `std::vector::at()`).
* **`std::invalid_argument`**: Passing unacceptable parameters (e.g., forcing an invalid string-to-number conversion).

### Runtime Errors (`std::runtime_error`)
*Derived from `std::exception`. These represent external environmental issues outside the program's direct control.*
* **`std::overflow_error`**: Arithmetic upper-limit boundaries exceeded.
* **`std::underflow_error`**: Floating-point minimum limit boundaries breached.

---

## 4. Best Practices

* **Catch by Const Reference**
  * *Rule*: Always use `catch (const std::exception& e)`.
  * *Reason*: Prevents "object slicing" (losing derived class data) and avoids the performance overhead of copying exception objects.
* **Order Hierarchy From Specific to Broad**
  * *Rule*: Place derived class `catch` blocks *before* base class `catch` blocks.
  * *Reason*: C++ checks catch handlers sequentially. A broad base class handler will intercept and mask a specialized derived handler if placed first.
* **Use the Catch-All Catch Block Sparingly**
  * *Rule*: Reserve `catch (...)` strictly as the final safety net in a `try-catch` chain.
  * *Reason*: It captures unknown or non-standard types but strips away all type visibility, making deep debugging impossible. Use it primarily for logging and minimal cleanup before terminating.

### Recommended Multi-Catch Layout
```cpp
try {
    // Complex application logic
} 
catch (const std::out_of_range& e) {
    // 1. Specific Logic Error handled first
    std::cerr << "Index Error: " << e.what() << std::endl;
} 
catch (const std::logic_error& e) {
    // 2. Broad Logic Error handled second
    std::cerr << "General Logic Bug: " << e.what() << std::endl;
} 
catch (const std::exception& e) {
    // 3. Fallback for any other standard exception
    std::cerr << "Standard Exception: " << e.what() << std::endl;
} 
catch (...) {
    // 4. Ultimate safety net for non-standard throws
    std::cerr << "Unknown critical error occurred." << std::endl;
}
```
