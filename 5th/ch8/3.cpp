#include <iostream>
using namespace std;

class Complex{
    public:
        Complex(): real(0), imaginary(0) {} 
        Complex(double realPart): real(realPart), imaginary(0) {}
        Complex(double realPart, double imaginaryPart): real(realPart), imaginary(imaginaryPart) {}
        friend bool operator == (const Complex& param1, const Complex& param2);
        friend Complex operator + (const Complex& param1, const Complex& param2);
        friend Complex operator - (const Complex& param1, const Complex& param2);
        friend Complex operator * (const Complex& param1, const Complex& param2);
        friend istream& operator >> (istream& paramIn, Complex& param);
        friend ostream& operator << (ostream& paramOut, const Complex& param);
    private:
        double real;
        double imaginary;
};

int main(){
    const Complex i(0, 1);
    Complex a(1), b(5, 13), c;

    cout << b << endl;
    cout << a * i << endl << b * i << endl;
    cout << b + a << endl << b - a << endl;
    cout << (a == b) << endl;

    cin >> c;
    cout << c << endl;

    return 0;
}

bool operator == (const Complex& param1, const Complex& param2){
    if (param1.real == param2.real && param1.imaginary == param2.imaginary)
        return true;
    else
        return false;
}

Complex operator + (const Complex& param1, const Complex& param2){
    return Complex(param1.real + param2.real, param1.imaginary + param2.imaginary);
}

Complex operator - (const Complex& param1, const Complex& param2){
    return Complex(param1.real - param2.real, param1.imaginary - param2.imaginary);
}

Complex operator * (const Complex& param1, const Complex& param2){
    return Complex(param1.real * param2.real - param1.imaginary * param2.imaginary,
                   param1.real * param2.imaginary + param1.imaginary * param2.real);
}

istream& operator >> (istream& paramIn, Complex& param){
    cin >> param.real >> param.imaginary;
    return paramIn;
}

ostream& operator << (ostream& paramOut, const Complex& param){
    cout << param.real << " × " << param.imaginary << 'i';
    return paramOut;
}

/*
    Define a class for complex numbers. 
    A complex number is a number of the form
        a + b * i
    where for our purposes, a and b are numbers of type double, and i is a number that represents the quantity √-1. 
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