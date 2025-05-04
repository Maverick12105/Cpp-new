#include <iostream>
using namespace std;
#include <math.h>

class Myinteger{
    public:
        Myinteger();
        Myinteger(int intVal): mint(intVal) {}
        int getmint() {return mint;}
        void setmint(int mintVal) {mint = mintVal;}
        int operator [] (int index);
    private:
        int mint;
};

int main(){
    Myinteger x(418);

    cout << x[1] << endl
         << x[2] << endl
         << x[3] << endl
         << x[4];

    return 0;
}

int Myinteger::operator [] (int index){
    if ((mint / pow(10, index - 1) < 1))
        return -1;
    return mint / ((int) pow(10, index - 1)) % 10;
}

/*
    Define a class named MyInteger that stores an integer and has functions to get and set the integer's value. 
    Then, overload the [] operator so that the index returns the digit in position i, where i = 0 is the least-significant digit. 
    If no such digit exists then - 1 should be returned. 
    For example, if x is of type MyInteger and is set to 418, 
    then x[0] should return 8, x[1] should retyrb 1, x[2] should return 4, and x[3] should return -1. 
*/