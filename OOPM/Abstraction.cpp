#include <iostream>
#include <memory> // Required for modern C++ Smart Pointers (std::unique_ptr)
using namespace std;

// 1. THE ABSTRACT CLASS (INTERFACE)
class AskforPromotion {
public:
    // Pure virtual function makes this an Abstract Class.
    // Derived classes MUST implement this function.
    virtual void CheckPromotion() = 0; 
    
    // A virtual destructor ensures that when a derived class object 
    // is deleted via a base pointer, the derived destructor runs properly.
    virtual ~AskforPromotion() {} 
};

// 2. THE DERIVED CLASS (IMPLEMENTATION)
class Employee : public AskforPromotion {
public:
    string Name;
    string Company;
    int Age;

    // Constructor to easily create employees with values
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }

    void Introduce() {
        cout << "Name: " << Name << " | Company: " << Company << " | Age: " << Age << endl;
    }

    // Overriding the abstract class contract
    void CheckPromotion() override { 
        if (Age >= 30)
            cout << "[PROMOTION]: " << Name << " is eligible for promotion!" << endl;
        else
            cout << "[PROMOTION]: " << Name << " is not eligible yet." << endl;
    }
};

// 3. MAIN EXECUTION (DEMONSTRATING SYNTAXES)
int main() {
    // Standard Stack-allocated object
    Employee emp1("Raj", "Microsoft", 30);
    emp1.Introduce();


    // APPROACH A: The Raw Pointer Syntax
    // 1. We create a pointer typed to the Base abstract class (*).
    // 2. We point it to the memory address (&) of our local Employee object.
    // 3. We use the arrow operator (->) to call the overridden method.
    AskforPromotion* rawPointer = &emp1;
    
    cout << "A) Using Raw Pointer (* and &):" << endl;
    rawPointer->CheckPromotion(); 
    cout << endl;


    // APPROACH B: The Reference Syntax (Cleaner Alternative)
    // 1. We create an alias/reference (&) typed to the Base abstract class.
    // 2. We bind it directly to 'emp1' without needing the address-of (&) symbol.
    // 3. We use standard dot notation (.). References cannot be empty (nullptr).
    AskforPromotion& promoRef = emp1;
    
    cout << "B) Using C++ References (& and .):" << endl;
    promoRef.CheckPromotion(); 
    cout << endl;


    // APPROACH C: Modern C++ Smart Pointer (Recommended for Heap Objects)
    // 1. 'std::make_unique' allocates an Employee object dynamically on the heap.
    // 2. We store it inside an abstract class unique_ptr wrapper.
    // 3. It uses the arrow operator (->) to access methods polymorphically.
    // 4. CRITICAL ADVANTAGE: When 'smartPtr' goes out of scope at the end of main,
    //    it automatically deletes the heap memory. Zero memory leaks!
    std::unique_ptr<AskforPromotion> smartPtr = std::make_unique<Employee>("Sriya", "Google", 25);
    
    cout << "C) Using Modern Smart Pointers (std::unique_ptr):" << endl;
    smartPtr->CheckPromotion(); 
    cout << endl;


    // APPROACH D: Legacy Raw Heap Allocation (The 'new' keyword)
    // 1. 'new Employee(...)' manually creates an object out on the heap memory.
    // 2. It returns a raw memory address, which we catch with an abstract pointer.
    // 3. CRITICAL DANGER: If you forget to call 'delete', this memory stays 
    //    trapped until the program closes (Memory Leak). Discouraged in Modern C++.
    AskforPromotion* legacyHeapPtr = new Employee("Amit", "Apple", 35);
    
    cout << "D) Using Legacy Raw Heap Allocation (new/delete):" << endl;
    legacyHeapPtr->CheckPromotion();
    
    // We MUST clean this up manually:
    delete legacyHeapPtr; 
    cout << endl;

    return 0;
}
