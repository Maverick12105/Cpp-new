#include <iostream>
using namespace std;

class primeNumber{
    public:
        primeNumber(): pNum(1) {}
        primeNumber(int numVal): pNum(numVal) {}
        void setpNum(int numVal) {pNum = numVal;}
        int operator ++ ();
        int operator ++ (int);
        int operator -- ();
        int operator -- (int);
    private:
        int pNum;
};

int main(){
    primeNumber x(13);

    cout << ++x << endl
         << x++ << endl
         << --x << endl
         << x--;

    return 0;
}

int primeNumber::operator ++ (){
    bool flag;
    int i = pNum;
    while (true){
        flag = false;
        ++i;
        for (int j = 2; j < i / j; ++j)
            if ((i % j) == 0){
                flag = true;
                break;
            }
        if (!flag)
            return i;
    }
}

int primeNumber::operator ++ (int){
    bool flag;
    int i = pNum;
    while (true){
        flag = false;
        ++i;
        for (int j = 2; j < i / j; ++j)
            if ((i % j) == 0){
                flag = true;
                break;
            }
        if (!flag)
            return i;
    }
}

int primeNumber::operator --(){
    bool flag;
    for (int i = pNum; i > 0; --i){
        flag = false;
        for (int j = 2; j < i / j; ++j)
            if (i % j == 0){
                flag = true;
                break;
            }
        if (!flag)
            return i;
    }
}

int primeNumber::operator --(int){
    bool flag;
    for (int i = pNum; i > 0; --i){
        flag = false;
        for (int j = 2; j < i / j; ++j)
            if (i % j == 0){
                flag = true;
                break;
            }
        if (!flag)
            return i;
    }
}

/*
    Define a class named primeNumber that stores a prime number. 
    The default constructor should set the prime number to 1. 
    Add another constructor that allows the caller to set the prime number. 
    Also, add a function to set the prime number. 
    Finally, overload the prefix and postfix ++ and -- operators 
    so they return a PrimeNumber object that is the next largest (for ++) and the next smallest prime number (for --). 
    For example, if the object's prime number is set to 13, then invoking ++ should return a primeNumber object whose prime number is set to 17. 
    Create an appropriate test program for the class. 

*/