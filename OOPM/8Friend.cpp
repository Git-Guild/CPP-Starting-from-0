#include <iostream>
#include <cmath>
using namespace std;

/*
! Friend Function:
* A friend function is a function that can access private members of a class.
* It is used to provide access to private members of a class.
*/

class EquilateralTriangle {
    float side;
    float perimeter;
    float area;
    public:
    friend float area(EquilateralTriangle et);
    friend float perimeter(EquilateralTriangle et);
    friend class Homework; // you can even create a friend class
    void setSide(float side) {
        this->side = side;
        area = sqrt(3.0) * side * side / 4.0;
        perimeter = side*3;
    }
};

class Homework{
    public:
    void printResults(EquilateralTriangle& et) {
        cout << "Perimeter: " << perimeter(et) << endl;
        cout << "Area: " << area(et) << endl;
    }
};

float area(EquilateralTriangle et) {
    return et.area;
}

float perimeter(EquilateralTriangle et) {
    return et.perimeter;
}


int main() {
    EquilateralTriangle et;
    et.setSide(3.0);
    Homework hw;
    hw.printResultsFromClass(et);
    return 0;
}