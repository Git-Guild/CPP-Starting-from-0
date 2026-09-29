#include <iostream>
using namespace std;

class Employee{
private: //! Encapsulation: private variables are only accessible inside the class
    string Name;
    string Company;
    int Age;
    
public:
// * getters and setters are used to access private variables
    void setName(string name){ //! setters are used to change private variables
        Name = name;
    }
    void setCompany(string company){
        Company = company;
    }
    void setAge(int age){
        if(age > 18)
        Age = age; //! age can't be less than 18 but if tried to change the age it will not and will be set to the previous given age only
    //! However, if no age is given previously this code will not run
    }
    
    string getName(){ //! getters are used to access private variables
        return Name;
    }
    string getCompany(){
        return Company;
    }
    int getAge(){
        return Age;
    }
    
    void Introduce(){
        cout << "Name:" << Name << endl;
        cout << "Company:" << Company << endl;
        cout << "Age:" << Age << endl;
    }
    
};

int main() {
    Employee emp1;
    emp1.setName("Raj");
    emp1.setCompany("Microsoft");
    emp1.setAge(30); //! If age is less than 18 it will give bullshit numbers
    
    emp1.Introduce();

    cout << emp1.getName() << " is " << emp1.getAge() << " years old and works at " << emp1.getCompany() << endl;
    
    return 0;
}