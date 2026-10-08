#include <iostream>
#include <string>
using namespace std;

//! Interfaces: contains exclusively pure virtual functions and no member variables. Because C++ natively supports multiple inheritance, a single concrete class can inherit (implement) as many of these abstract classes as needed

class Animal {
    public:
    virtual void eat() = 0; //! pure virtual function
    virtual void makeSound() const = 0; //must be in child classes

    virtual ~Animal() {} // Virtual destructor AVOIDS MEMORY LEAKS when deleting objects
};

class Dog : public Animal {
    public:
    void makeSound() const override{ // const menas only read data, no modification
        cout << "Woof!" << endl;
    }
    void eat() override{ //! Asks the compiler to verify this function exactly matches the interface, just a compiler check
        cout << "Eating Pedigree..." << endl;
    }
};

class Cat : public Animal {
    public:
    void makeSound() const override {
        cout << "Meow!" << endl;
    }
    void eat() override{
        cout << "Eating Catnip..." << endl;
    }
};

int main() {
    Animal* animals[2];
    animals[0] = new Dog();
    animals[1] = new Cat();

    for (int i = 0; i < 2; i++) {
        animals[i]->makeSound();
        animals[i]->eat();
    }
    for (int i = 0; i < 2; i++) {
        delete animals[i]; // delete individual objects for memory deallocation
    }

    return 0;
}