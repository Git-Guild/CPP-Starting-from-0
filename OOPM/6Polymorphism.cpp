#include <iostream>
#include <string>
using namespace std;

class Employee {
protected: 
    //! 'protected' allows derived classes to access these variables directly, 
    //* while keeping them hidden from the outside world (main function).
    string Name;
    string Company;
    int Age;

public:
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }

    string getName() {
        return Name;
    }

    //! POLYMORPHISM KEYPOINT: The 'virtual' keyword.
    // This tells the compiler to look for an overridden version of this 
    // function in the derived class at RUNTIME (Dynamic Binding / Late Binding).
    virtual void Work() {
        cout << Name << " is checking emails and performing general tasks." << endl;
    }

    virtual ~Employee() {}
};

class Dev : public Employee {
public:
    string favLanguage;

    Dev(string name, string company, int age, string language) 
        : Employee(name, company, age) { // Forward parameters to Employee
        favLanguage = language;
    }

    //! POLYMORPHISM KEYPOINT: Overriding the virtual function.
    // The 'override' keyword is optional but highly recommended. It tells the 
    // compiler to double-check that this function matches a virtual function in the base class.
    void Work() override {
        // Because Name is 'protected' in Employee, we can access it directly here
        cout << Name << " is writing code in " << favLanguage << " and fixing bugs!" << endl;
    }
};

int main() {
    Dev d = Dev("Raj", "Google", 29, "C++");

    //! Create a Base Class Pointer pointing to the Derived Class Object
    // This is the core setup for achieving runtime polymorphism.
    Employee* e = &d;

    cout << "--- Calling Work() via Base Class Pointer ---" << endl;
    
    //! Execute the virtual function using the pointer (e->Work())
    // Even though 'e' is an Employee pointer, it executes Dev's version of Work().
    // The C++ compiler resolves this at runtime because of the 'virtual' keyword.
    e->Work(); 

    cout << "\n--- Calling Work() via Object Directly ---" << endl;
    d.Work();

    return 0;
}
