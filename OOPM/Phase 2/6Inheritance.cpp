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

// * 1. Single Inheritance: Dev inherits directly from a single base class (Employee)
class Dev: public Employee{ 
    public:
        string favLanguage;
        Dev(string name, string company, int age, string favLanguage):Employee(name, company, age){ //* :Employee(...) passes arguments to the base constructor
            this->favLanguage = favLanguage;
        }
        void FixBug(){
            cout << getName() << " is fixing bug..." <<  endl;
        }
};

// * 2. Hierarchical Inheritance: Teacher inherits from Employee, just like Dev does (multiple classes from one base)
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

// * 3. Multilevel Inheritance: LeadDev inherits from Dev, which itself inherits from Employee (forming a chain)
class LeadDev: public Dev {
    public:
        int teamSize;
        LeadDev(string name, string company, int age, string favLanguage, int teamSize) : Dev(name, company, age, favLanguage) {
            this->teamSize = teamSize;
        }
        void ManageTeam() {
            cout << getName() << " is managing a team of " << teamSize << " developers." << endl;
        }
};

// * Supporting class for Multiple and Hybrid Inheritance
class Speaker {
    public:
        string Specialty;
        Speaker(string specialty) {
            Specialty = specialty;
        }
        void Speak() {
            cout << "[SPEAKER]: Speaking about " << Specialty << endl;
        }
};

// * 4. Multiple Inheritance: TechLead inherits from more than one base class simultaneously (Employee and Speaker)
class TechLead: public Employee, public Speaker {
    public:
        TechLead(string name, string company, int age, string specialty) : Employee(name, company, age), Speaker(specialty) {}
        void GuideProject() {
            cout << getName() << " is guiding the project architecture." << endl;
        }
};

// * 5. Hybrid Inheritance: A combination of two or more types of inheritance 
// * (e.g., Hierarchical structure combined with Multiple inheritance across the project schema)

int main() {
    // Single Inheritance test
    Dev d = Dev("Raj", "Google", 29, "C++");
    d.FixBug();
    d.Introduce();
    d.CheckPromotion();

    cout << endl;

    // Multilevel Inheritance test
    LeadDev ld = LeadDev("Aman", "Microsoft", 32, "C++", 5);
    ld.FixBug();
    ld.ManageTeam();
    ld.CheckPromotion();

    cout << endl;

    // Multiple Inheritance test
    TechLead tl = TechLead("Priya", "Amazon", 35, "System Design");
    tl.Introduce();
    tl.Speak();
    tl.GuideProject();
    tl.CheckPromotion();

    return 0;
}