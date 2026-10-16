#include <iostream>
using namespace std;

// ! Structs vs Classes
// before c++ came C and in C there were structures or STRUCT.
// STRUCT is a way to group data together and define a type for it.
// C++ extends this idea and make it in a class.
//* The only difference is that by default everything is public in C but private in C++
// we want to use classes as much as we can but in some instances like making a LinkedList we might prefer structs

struct Emp{ // as simple as possible
    string Name;
    string Company;
    int Age;
};

/*
Consider Class as a box or a blueprint of something
An object is a thing that belongs to this box
* More bookish: "A class is a blueprint of an object and an object is an instance of a class"
*/

class Employee{
public: //by default private (can't access outside class)
    string Name;
    string Company;
    int Age;

    void Introduce(){
        cout << "Name:" << Name << endl;
        cout << "Company:" << Company << endl;
        cout << "Age:" << Age << endl;
    }
    //! Function overloading: same function name, different parameters and will behave like a different function (this comes under Polymorphism, more in 4Polymorphism.cpp)
    void Introduce(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
        
        cout << "Name:" << Name << endl;
        cout << "Company:" << Company << endl;
        cout << "Age:" << Age << endl;
    }
    //* Function overloading does not only works with different parameters but also with different sequence of parameters
    void Introduce(int age, string company, string name){
        Name = name;
        Company = company;
        Age = age;
        
        cout << "Sequence changed parameteres:" << endl;
        cout << "Name:" << Name << endl;
        cout << "Company:" << Company << endl;
        cout << "Age:" << Age << endl;
    }
};

int main() {

    Employee emp1; // this is an object(emp1) of class Employee
    emp1.Name = "Yuvraj";
    emp1.Age= 19;
    emp1.Company = "Amazon";
    emp1.Introduce(); // if we don't call it by parameters, it will use the without parameters version
    
    Employee emp2;
    emp2.Introduce("Rahul", "Google", 39); // parameters version

    Employee emp3;
    emp3.Introduce(29, "Changed", "Sequence"); // we changed sequence and thus it will use the other version
    
    return 0;
}