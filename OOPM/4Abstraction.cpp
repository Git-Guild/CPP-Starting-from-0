// TODO: Abstraction is the way to show only the necessary information to the user like a TV button remote not the wiring of PCB inside it
#include <iostream>
#include <memory> // Required for modern C++ Smart Pointers (std::unique_ptr)
using namespace std;

// 1. THE ABSTRACT 
class AskforPromotion {
public:
    // Pure virtual function makes this an Abstract Class.
    // Derived classes MUST implement this function.
    virtual void CheckPromotion() = 0; 
    
    // A virtual destructor ensures that when a derived class object 
    // is deleted via a base pointer, the derived destructor runs properly.
    virtual ~AskforPromotion() {} 
};

// 2. THE DERIVED CLASS
class Employee : public AskforPromotion { //! : is used for inheritance and we can choose which data the inherited class can have access of parent class by public or private or protected

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
    //! Overriding the function is done by using the same function name but with a differnet code block
    void CheckPromotion() override { 
        if (Age >= 30)
            cout << "[PROMOTION]: " << Name << " is eligible for promotion!" << endl;
        else
            cout << "[PROMOTION]: " << Name << " is not eligible yet." << endl;
    }
};

// 3. MAIN EXECUTION
int main() {
    // Standard Stack-allocated object
    Employee emp1("Raj", "Microsoft", 30);
    emp1.Introduce();

    //! BASIC POINTER KNOWLEDGE IS NECESSARY FOR BELOW CODE
    /*
    ! pointers store the memory address of the object rather than direct value
    * pointers are used to access the data of the object without knowing the exact value of the object
    & this helps in less memory usage
    ! C++ syntax
    */

    // APPROACH A: The Raw Pointer Syntax
    // 1. We create a pointer 'rawPointer' of type 'AskforPromotion*' (Base Class).
    // 2. We set it to store the memory address of 'emp1' using the '&' symbol. * for declaring pointer and & for getting the address of the object
    // 3. We use the arrow operator (->) to call the overridden method.
    //* refer the most as is easier and widely used

    AskforPromotion* rawPointer = &emp1; //* Raw pointer stores the value of the address of the object rather than direct value
    
    cout << "A) Using Raw Pointer (* and &):" << endl;
    rawPointer->CheckPromotion(); 
    cout << endl;


    // APPROACH B: The Reference Syntax (Cleaner Alternative)
    // 1. We create an alias/reference (&) typed to the Base abstract class.
    // 2. We bind it directly to 'emp1' without needing the address-of (&) symbol.
    // 3. We use standard dot notation (.). References cannot be empty (nullptr).
    //! DO NOT USE FOR NULL POINTERS (nullptr)

    AskforPromotion& promoRef = emp1;
    
    cout << "B) Using C++ References (& and .):" << endl;
    promoRef.CheckPromotion(); 
    cout << endl;

/*
! Stack vs. Heap Memory:

* Stack: Fast, automatic memory allocation. Variables created here are automatically erased when the function ends.   

* Heap: Dynamic memory allocation where objects persist until explicitly deleted.

*/


    // APPROACH C: Modern C++ Smart Pointer (Recommended for Heap Objects)
    // 1. 'std::make_unique' allocates an Employee object dynamically on the heap.
    // 2. We store it inside an abstract class unique_ptr wrapper.
    // 3. It uses the arrow operator (->) to access methods polymorphically.
    // 4. CRITICAL ADVANTAGE: When 'smartPtr' goes out of scope at the end of main,
    //    it automatically deletes the heap memory. Zero memory leaks!
    //* Try to use the most of this in real life projects, better error handling and memory allocation, less human error

    std::unique_ptr<AskforPromotion> smartPtr = std::make_unique<Employee>("Sriya", "Google", 25);
    
    cout << "C) Using Modern Smart Pointers (std::unique_ptr):" << endl;
    smartPtr->CheckPromotion(); 
    cout << endl;


    // APPROACH D: Legacy Raw Heap Allocation (The 'new' keyword)
    // 1. 'new Employee(...)' manually creates an object out on the heap memory.
    // 2. It returns a raw memory address, which we catch with an abstract pointer.
    // 3. CRITICAL DANGER: If you forget to call 'delete', this memory stays 
    //    trapped until the program closes (Memory Leak). Discouraged in Modern C++.
    //* But kind of will be expected by you to use in exams because teachers are outdated
    //! NEVER USE IN REAL LIFE

    AskforPromotion* legacyHeapPtr = new Employee("Amit", "Apple", 35);
    
    cout << "D) Using Legacy Raw Heap Allocation (new/delete):" << endl;
    legacyHeapPtr->CheckPromotion();
    
    // We MUST clean this up manually:
    delete legacyHeapPtr; 
    cout << endl;

    return 0;
}
