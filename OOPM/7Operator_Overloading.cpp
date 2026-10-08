#include <iostream>
#include <string>
#include <list>
using namespace std;
/*
! Operator Overloading:
4+5 compiler knows what + do for integers
but let's say you made a class Car and you want to use + operator for it
car1+car2: what will this do?
* Overloading is the process of creating new operators for a class.
* It is done by creating a new function with the same name as the operator.
* The new function must have the same parameters as the operator.
*/

class Car {
    public:
        string brand;
        int speed;
        int distance;
        Car(string brand, int speed, int distance) {
            this->brand = brand;
            this->speed = speed;
            this->distance = distance;
        }
        Car operator+(const Car& other) { /*
            *defines what happens when the + operator is used b/w two car objects
            * 'const Car& other' is used for right side car object 
            * & is used so it doesn't make an expensive copy of the object
            * const means it doesn't change the object
            */
            return Car( // a new car object made of two objects
                    this->brand + " & " + other.brand,
                    this->speed + other.speed, 
                    this->distance + other.distance
                );
            }
            bool operator==(const Car& other) const {// so it can compare cars and we can use .remove(car)
                return (this->brand == other.brand && 
                        this->speed == other.speed && 
                        this->distance == other.distance);
            }
};

ostream& operator<<(ostream& COUT, const Car& car) { //! we need cout and car1 to work together
    //* ostream is what cout uses to output data and we refrence it using & because these are not cheap to copy like integers
    //! refrence to  ostream& so cout can give chained results a << b << c
    COUT << "Car: " << car.brand << " | Speed: " << car.speed << " | Distance: " << car.distance << endl;
    return COUT;
}

class MyCollection {
    public:
    list<Car> myCars;
    void operator+=(const Car& car) {
        //* overloading += operator
        this->myCars.push_back(car);
    }
    void operator-=(const Car& car) {
        //* overloading += operator
        this->myCars.remove(car);
    }
};
ostream& operator<<(ostream& COUT, const MyCollection& myCollection) {
    for (Car car:myCollection.myCars) {
        COUT << car;
    }
    return COUT;
}

int main() {
    Car car1("Audi", 100, 1000);
    Car car2("BMW", 80, 2000);
    Car car3("Mercedes", 120, 3000);
    cout << car1 + car2 + car3;

    MyCollection myCollection;


    myCollection += car1;
    myCollection += car2;
    myCollection += car3;
    myCollection -= car2;

    cout << myCollection; 

    /*
    ! The regular way:
    myCollection.myCars.push_back(car1);
    myCollection.myCars.push_back(car2);
    myCollection.myCars.push_back(car3);

    for (auto car : myCollection.myCars) {
        cout << car;
    }
    */
    return 0;
}