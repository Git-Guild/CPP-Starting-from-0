# include <iostream>
using namespace std;

class AskforPromotion {
    public:
        virtual void CheckPromotion() = 0; 
        
        virtual ~AskforPromotion() {} 
    };

class Employee: public AskforPromotion{
    private:
        string Name;
        string Company;
        int Age;
    public:

        void setName(string name){
            Name = name;
        }

        void setCompany(string company){
            Company = company;
        }

        void setAge(int age){
            Age = age;
        }


        string getName(){
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

        Employee(string name, string company, int age){
            Name = name;
            Company = company;
            Age = age;
        }

        void CheckPromotion() override { 
            if (Age >= 30)
                cout << "[PROMOTION]: " << Name << " is eligible for promotion!" << endl;
            else
                cout << "[PROMOTION]: " << Name << " is not eligible yet." << endl; 
        }
};

class Dev: public Employee{ // we can choose what access the child class will have from parent class by public or private or protected
    public:
        string favLanguage;
        Dev(string name, string company, int age, string favLanguage):Employee(name, company, age){ //* :Employee(name, company, age) is used because we are inheriting from Employee and the constructor of Employee already had this parameter
            this->favLanguage = favLanguage;
        }
        void FixBug(){
            cout << getName() << " is fixing bug..." <<  endl;
        }
};

class Teacher: public Employee{ //! Try to use yourself and experiment
    public:
        string Subject;
        Teacher(string name, string company, int age, string subject):Employee(name, company, age){
            Subject = subject;
        }
        void Teach(){
            cout << getName() << " is teaching " << Subject << endl;
        }
};

int main() {
    Dev d=Dev("Raj", "Google", 29, "C++");
    d.FixBug();
    d.Introduce();
    d.CheckPromotion();
    return 0;
}