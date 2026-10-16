#include <iostream>
#include <string>
using namespace std;

/*
! Static Members in C++:
* Static variables belong to the class itself, not to any specific object instance.
* This means all objects share a single copy of a static variable.
* Static functions can only access other static members and do not have a 'this' pointer.
*/

class Employee {
    private:
        string Name;
        string Company;
        int Age;
    public:
        // * Static member variable to track total employee count globally across all objects
        static int employeeCount;

        Employee(string name, string company, int age) {
            Name = name;
            Company = company;
            Age = age;
            employeeCount++; // * Increment count every time a new object is instantiated
        }

        void Introduce() {
            cout << "Name: " << Name << " | Company: " << Company << " | Age: " << Age << endl;
        }

        // * Static member function to print the count
        static void PrintEmployeeCount() {
            cout << "[TOTAL EMPLOYEES]: " << employeeCount << endl;
        }
};

// * Static member variables must be initialized outside the class definition
int Employee::employeeCount = 0;

int main() {
    // * Call static function before any objects are created
    Employee::PrintEmployeeCount();

    Employee emp1("Raj", "Google", 29);
    Employee emp2("Aman", "Microsoft", 32);
    Employee emp3("Priya", "Amazon", 27);

    emp1.Introduce();
    emp2.Introduce();
    emp3.Introduce();

    // * Accessing static function via class name
    Employee::PrintEmployeeCount();

    return 0;
}