# C++ Starting from Zero

A hands-on learning repository for C++ fundamentals, object-oriented programming, and small practical projects. Designed for beginners who want to learn C++ by reading, modifying, and running real code examples.

Maintained by [GitGuild](https://github.com/gitguild).

## Video Resources

These videos walk through the concepts covered in this repository. Follow along with the code examples as you watch.

| Topic | Video |
|-------|-------|
| C++ Full Course (Beginner to Advanced) | [YouTube](https://youtu.be/-TkoO8Z07hI) |
| Object-Oriented Programming in C++ | [YouTube](https://youtu.be/wN0x9eZLix4) |

## Repository Structure

```
CPP-Starting-from-0/
├── Learning/          # Core C++ concept examples, ordered by topic
├── OOPM/              # Object-Oriented Programming & Modularity examples
├── Basic DSA/         # Data structures (linked lists, and more over time)
└── Projects/          # Mini-projects combining everything learned
```

## Learning Path

Follow the files in order to progress from basics to more advanced concepts.

### 1. Learning — Core Concepts

| # | File | Topics Covered |
|---|------|----------------|
| 1 | `1First_Steps.cpp` | Output, variables, data types, arithmetic, user input, math functions |
| 2 | `2Conditions.cpp` | `if`, `else if`, `else`, comparison operators |
| 3 | `3StringsAndLoops.cpp` | String manipulation, `for` loops, `while` loops |
| 4 | `4Function_Overloading.cpp` | Writing functions, overloading (same name, different parameters) |
| 5 | `5Arrays_and_foreachloop.cpp` | Arrays, range-based `for` loops |
| 6 | `6MemoryAddresses.cpp` | Pointers, memory addresses, pass-by-reference |
| 7 | `7RecursionsANDStructs.cpp` | Recursion, `struct` definition and usage |
| 8 | `8OOPS.cpp` | Classes, objects, access modifiers, basic OOP |
| 9 | `9Overloading.cpp` | Operator and function overloading |
| 10 | `CollegeOverloading.cpp` | Additional overloading exercises |
| 11 | `HigherCollegeOverloading.cpp` | Advanced overloading examples |
| 12 | `Matrix.cpp` | 2D arrays and matrix operations |

### 2. OOPM — Object-Oriented Programming & Modularity

Organized into three phases of increasing difficulty. Complete them in order.

**Phase 1 — Fundamentals**

| File | Topics Covered |
|------|----------------|
| `Phase 1/1Classes and Objects.cpp` | Defining classes, creating objects, public members |
| `Phase 1/2Constructor.cpp` | Constructors, parameterized initialization |
| `Phase 1/3Encapsulation.cpp` | Getters, setters, encapsulation principles |
| `Phase 1/4Polymorphism.cpp` | `virtual` functions, runtime polymorphism, base-class pointers |

**Phase 2 — Pillars**

| File | Topics Covered |
|------|----------------|
| `Phase 2/5Abstraction.cpp` | Abstract classes, pure virtual functions, interfaces, smart pointers |
| `Phase 2/6Inheritance.cpp` | Base and derived classes, `protected`, access specifiers, multilevel inheritance |
| `Phase 2/7Static_Members.cpp` | Static data members, static member functions, class-level state |

**Phase 3 — Advanced**

| File | Topics Covered |
|------|----------------|
| `Phase 3/7Operator_Overloading.cpp` | Making operators (`+`, `==`, `+=`, `-=`, `<<`) work on your own classes |
| `Phase 3/8Friend.cpp` | Friend functions and friend classes |
| `Phase 3/9More_About_Constructors.cpp` | Default vs parameterized constructors, copy/move semantics (`std::move`), releasing owned heap memory |
| `Phase 3/Error_Handling.cpp` | `try`/`throw`/`catch`, the full `std::exception` hierarchy, custom exceptions, `noexcept` |
| `Phase 3/ErrorHandling.md` | Written reference: exception hierarchy, common error codes, best practices |

**Practice**

| File | Topics Covered |
|------|----------------|
| `Practice/ElecBill.cpp` | Constructor-based initialization in a small program (electricity bill) |
| `Practice/Operator_Overloading_using_Friend.cpp` | Overloading `+` for a `Complex` class with a friend function |

### 3. Basic DSA — Data Structures

Start after `Learning/` files 6–8 (pointers, structs, classes). See [`Basic DSA/README.md`](Basic%20DSA/README.md) for the full guide, and [`Basic DSA/Linked List/README.md`](Basic%20DSA/Linked%20List/README.md) for the concept deep-dive and verified output of every file.

| File | Topics Covered |
|------|----------------|
| `Linked List/BasicLinkedList.cpp` | Manual node creation and linking, `class Node` vs `struct`, `this`, `nullptr` vs `NULL`, traversal, freeing the heap with a `delete` loop |
| `Linked List/LinkedList.cpp` | The practical approach: wrapping the list in a `LinkedList` class — constructor for `head`, `add()` and `print()` methods, objects in `main` |
| `Linked List/Insertion/InsertAtFirst.cpp` | Node anatomy, head pointer, `Node *&head` (reference-to-pointer), insert at front O(1), traversal, `new`, `nullptr` |
| `Linked List/Insertion/InsertAtLast.cpp` | Empty-list handling, walking to the last node, append O(n) |
| `Linked List/Insertion/InsertAtPos.cpp` | 1-indexed insertion, bounds checking, splicing nodes |
| `Linked List/Deletion/delAtBegin.cpp` | Delete at front: empty-list guard, moving `head` forward before `delete`, O(1) |

Read them in that order — each file builds on the one before it.

### 4. Projects — Practice Projects

| File | Description |
|------|-------------|
| `Banking_program.cpp` | Deposit, withdrawal, and balance checking with input validation |
| `Credit_CardValidator.cpp` | Luhn algorithm implementation for card number validation |
| `Quiz.cpp` | Interactive quiz application |
| `Random_game.cpp` | Number guessing game |
| `TTT.cpp` | Tic-Tac-Toe game |

## Getting Started

### Prerequisites

- A C++ compiler (GCC, Clang, or MSVC)
- A text editor or IDE (VS Code recommended)

### Running the Examples

**Using g++ (Linux/macOS/MinGW):**

```bash
g++ Learning/1First_Steps.cpp -o first_steps
./first_steps
```

**Using VS Code with the C/C++ Extension Pack:**

1. Install the [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack) from the VS Code Marketplace.
2. Open the folder in VS Code.
3. Open any `.cpp` file and press `Ctrl+F5` to run without debugging, or `F5` to run with debugging.

**Using Visual Studio (Windows):**

1. Create a new **Console Application** project.
2. Replace the generated code with the contents of any `.cpp` file.
3. Press `Ctrl+F5` to build and run.

## Recommended VS Code Extensions

| Extension | Purpose |
|-----------|---------|
| **C/C++ Extension Pack** | Core C/C++ language support, debugging, and IntelliSense |
| **C++ Quick Start Snippets** | Common C++ templates and code snippets |
| **Code Runner** | Compile and run code directly from the editor |
| **Code Spell Checker** | Catch spelling mistakes in comments and strings |
| **Colorful Comments** | Highlight special comments like `TODO`, `NOTE` for readability |
| **Indent Rainbow** | Visual indentation guides for easier alignment |

## Contributing

Contributions are welcome. If you have suggestions for new examples or improvements:

1. Fork the [repository](https://github.com/gitguild/CPP-Starting-from-0).
2. Create a new branch for your changes.
3. Add or modify `.cpp` files following the existing naming and structure conventions.
4. Open a pull request with a clear description of what was added or changed.

## License

This repository is available under the [MIT License](LICENSE).
