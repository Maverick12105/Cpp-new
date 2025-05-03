#include <iostream>
using namespace std;

int main(){
    cout << "hello world";

    return 0;
}

/*
    Define a class for complex numbers. 
    A complex number is a number of the form
        a + b * i
    where for out purposes, a and b are numbers of type double, and i is a number that represents the quantity √-1. 
    Repersent a complex number as two values of type double. 
    Name the member variable real and imaginary. (The variable for the number that is multiplied by i is the one called imaginary.)
    Call the class Complex. 
    Include a constructor with two parameters of type double that can be used to set the member variables of an object to any values. 
    Include a constructor that has only a single parameter of type double;
    call this realPart and define the constructor so that the object will be initialized to realPart + 0 * i. 
    Overload all the following operators so that they correctly apply to the type Complex: ==, +, -, *, >>, and <<. 
    You should also write a test program to test your class. 
    Hints: To add or subtract two complex numbers, add or subtract the two member variables of ytpe double. 
    The product of two complex numbers is given by the following formula:
        (a + b * i) * (c + d * i) == (a * c - b * d) + (a * d + b * c) * i
    In the interface file, you should define a constant i as follows: 
        const Complex i(0, 1);
    This defined constant i will be the same as the i discussed above. 
*/