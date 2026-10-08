// TODO: WAP to make an electricity bill that can be calculated and displayed and subisdy and cost per unit is given by units burned

#include <iostream>
using namespace std;

class Bill {
    int id, units;
    string name;

public:
    Bill(int id, int units, string name) { // Make a constructor to initialize the variables at once rather than taking inputs
        this->id = id;
        this->units = units;
        this->name = name; //! This pointer is used when the variable name is same in both class and constructor/function
    }

    int calc(); //* Outline function: we declare this first here and define later (it will still use the class' variables)
    void display();
};

// Corrected operator to <=
int Bill::calc() { //! type class::function to define an outline function
    if (units <= 50) {
        return 0;
    } 
    else if (units <= 300) {
        return ((units - 50) * 3);
    } 
    else if (units <= 500) {
        return ((units - 75) * 5);
    } 
    else {
        return ((units - 100) * 7);
    }
}

void Bill::display() {
    cout << "Name: " << name << endl;
    cout << "Id: " << id << endl;
    cout << "Units: " << units << endl;
    cout << "Price: " << calc() << endl; 
}

int main() {
    Bill b(700, 999, "Yuvraj");
    
    b.display(); // just by calling one function, all results are printed
    
    return 0;
}
