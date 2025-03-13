#include <iostream>
#include <stdexcept>

class Counter{
    public:
        int number;

        void operator ++(){
            number += 1;
        }

        void operator ++(int){
            number += 1;
        }
};

class Complex{
    public:
        float real;
        float imaginary;

        Complex(float r, float i){
            real = r;
            imaginary = i;
        }

        Complex operator +(Complex other){
            return Complex(real + other.real, imaginary + other.imaginary);
        }
};

class Point{
    public:
        float x;
        float y;

        Point(float x_value, float y_value){
            x = x_value;
            y = y_value;
        }

        bool operator ==(Point other){
            return ((x == other.x) && (y == other.y));
        }
};

class Array{
    public:
        int array[5];

        int operator [](int i){
            if (i > 4){
                throw std::out_of_range("Index out of bounds");
            }
            else{
                return array[i];
            }
        }
};

class Multiply{
    public:
        int operator ()(int a, int b){
            return a * b;
        }
};

int main(){

    return 0;
}