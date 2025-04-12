#include <iostream>
using namespace std;

class Pizza{
    public:
        void setType();
        void setSize();
        void setToppings();
        char getType();
        char getSize();
        int getToppings();
    private:
        char type;
        char size;
        int toppings;
};

void outputDescription(Pizza pizza);
double computePrice(Pizza pizza);

int main(){
    char repeat;
    Pizza pizza;

    do{
        pizza.setSize();
        pizza.setType();
        pizza.setToppings();
        
        outputDescription(pizza);
        cout << "will be " << computePrice(pizza) << '$' << endl << endl;

        cout << "Repeat?(y/n) => ";
        cin >> repeat;
    }while (repeat == 'y');
    
    
    return 0;
}

void Pizza::setType(){
    while(true){
        cout << "Type(d/h/p) => ";
        cin >> type;
        if(type == 'd' || type == 'h' || type == 'p')
            break;
        cout << "Invalid input, try again." << endl;
    }
}

void Pizza::setSize(){
    while(true){
        cout << "Size(l/m/s) => ";
        cin >> size;
        if(size == 'l' || size == 'm' || size == 's')
            break;
        cout << "Invalid input, try again." << endl;
    }
}

void Pizza::setToppings(){
    while(true){
        cout << "Toppings amount => ";
        cin >> toppings;
        if(toppings >= 0)
            break;
        cout << "Invalid input, try again." << endl;
    }
}

char Pizza::getType(){
    return type;
}

char Pizza::getSize(){
    return size;
}

int Pizza::getToppings(){
    return toppings;
}

void outputDescription(Pizza pizza){
    cout << endl;
    switch (pizza.getSize()){
        case 'l':
            cout << "Large ";
            break;
        case 'm':
            cout << "Medium ";
            break;
        case 's':
            cout << "Small ";
            break;
    }

    switch (pizza.getType()){
        case 'd':
            cout << "deep dish ";
            break;
        case 'h':
            cout << "hand toss ";
            break;
        case 'p':
            cout << "pan ";
            break;
    }

    cout << "pizza with " << pizza.getToppings() << " addtional topping ";
}

double computePrice(Pizza pizza){
    switch (pizza.getSize()){
        case 'l':
            return 17 + pizza.getToppings() * 2;
        case 'm':
            return 14 + pizza.getToppings() * 2;
        case 's':
            return 10 + pizza.getToppings() * 2;
    }
}

/*
Define a class called Pizza that has member variables to track the type of pizza(either deep dish, hand tossed, or pan)
along with the size (either small, medium, or large) and the number of pepperoni or cheese toppings.
You can use constants to represent the type and size.
Include mutator and accessor functions for your class.
Create a void function, outputDescription(), that outputs a textual description of the pizza object. 
Also include a function, computePrice(), that computes the cost of the pizza and returns it as a double 
according to the following rules:
    Small pizza = $10 + $2 per topping
    Medium pizza = $14 + $2 per topping
    Large pizza = $17 + $2 per topping
Write a suitable test program that creates and outputs a description and price of various pizza objects. 
*/