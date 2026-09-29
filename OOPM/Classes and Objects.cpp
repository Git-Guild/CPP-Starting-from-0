#include <iostream>
using namespace std;

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
};

int main() {
    Employee emp1;
    emp1.Name = "Yuvraj";
    emp1.Age= 19;
    emp1.Company = "Amazon";
    emp1.Introduce();
    
    Employee emp2;
    emp2.Name = "Rahul";
    emp2.Age= 29;
    emp2.Company = "Google";
    emp2.Introduce();
    
    return 0;
}