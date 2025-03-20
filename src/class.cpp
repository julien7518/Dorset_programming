#include <iostream>
#include <string>
using namespace std;

// Single Inheritance
class Person{
    public:
        string name;

        void introduce(){
            cout << "Hello, I'm " << name << endl;
        }
};

class Student: public Person{
    public:
        void study(){
            cout << "I'm studying engineering" << endl;
        }
};

// Multiple Inheritance
class Bird{
    public:
        void fly(){
            cout << "Flying" << endl;
        }
};

class Vehicle{
    public:
        void drive(){
            cout << "Driving" << endl;
        }
};

class FlyingCar: public Bird, public Vehicle{
    public:
        void flyAndDrive(){
            drive();
            fly();
        }
};

// Multilevel inheritance
class Animal{
    public:
        void eat(){
            cout << "Eating" << endl;
        }
};

class Mammal{
    public:
        void walk(){
            cout << "Walking" << endl;
        }
};

class Bird2{
    public:
        void chrip(){
            cout << "Chirping" << endl;
        }
};

class Bat: public Bird2, public Mammal{
    public:
        void fly(){
            cout << "Flying" <<  endl;
        }
};

int main(){
    Student s;
    s.name = "John Doe";
    s.introduce();
    s.study();

    return 0;
}