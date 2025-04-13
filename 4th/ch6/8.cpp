#include <iostream>
using namespace std;

class Money{
    public:
        int getDollars();
        int getCents();
        void setDollars(double iTemp);
        void setCents(double iTemp);
        double monetaryAmount();
    private:
        int dollars;
        int cents;
};

int main(){
    char repeat;
    Money money1, money2;
    double iTemp;

    do{
        cout << "Monetary amount => ";
        cin >> iTemp;
        money1.setDollars(iTemp);
        money1.setCents(iTemp);
        cout << money1.monetaryAmount();
        cout << endl;

        cout << "Monetary amount => ";
        cin >> iTemp;
        money2.setDollars(iTemp);
        money2.setCents(iTemp);
        cout << money2.monetaryAmount();
        cout << endl;

        cout << endl << "Repeat?(y/n) => ";
        cin >> repeat;
    }while (repeat == 'y');
    
    return 0;
}

int Money::getDollars(){
    return dollars;
}

int Money::getCents(){
    return cents;
}

void Money::setDollars(double iTemp){
    dollars = (int) iTemp;
}

void Money::setCents(double iTemp){
    cents = (iTemp - (int) iTemp) * 100;
}

double Money::monetaryAmount(){
    return dollars + cents * 0.01;
}

/*
Define a class named Money that stores a monetary amount.
The class should have two private integer variables, one to store the number of dollars and another to store the number of cents. 
Add accessor and mutator functions to read and set both member variables. 
Add another function that returns the monetary amount as a double. 
Write a program that tests all of your functions with at least two different Money objects. 
*/