#include <iostream>
using namespace std;

class Weight{
    public:
        void setWeightPounds();
        void setWeightKilograms();
        void setWeightOunces();
        double getWeightPounds();
        double getWeightKilograms();
        double getWeightOunces();
    private:
        double pounds;
};

int main(){
    char repeat;
    char weightType;
    Weight weight;

    do{
        cout << "p/k/o => ";
        cin >> weightType;

        switch (weightType){
            case 'p':
                weight.setWeightPounds();
                break;
            case 'k':
                weight.setWeightKilograms();
                break;
            case 'o':
                weight.setWeightOunces();
                break;
        }

        cout << endl;
        cout << "Pounds = " << weight.getWeightPounds() << endl;
        cout << "Kilograms = " << weight.getWeightKilograms() << endl;
        cout << "Ounces = " << weight.getWeightOunces() << endl;

        cout << endl << "Repeat?(y/n) => ";
        cin >> repeat;
    }while (repeat == 'y');
    
    return 0;
}

void Weight::setWeightPounds(){
    double weight;
    cout << "Pounds = ";
    cin >> weight;
    pounds = weight; 
}

void Weight::setWeightKilograms(){
    double weight;
    cout << "Kilograms = ";
    cin >> weight;
    pounds = weight * 2.21; 
}

void Weight::setWeightOunces(){
    double weight;
    cout << "Ounces = ";
    cin >> weight;
    pounds = weight / 16; 
}

double Weight::getWeightPounds(){
    return pounds;
}

double Weight::getWeightKilograms(){
    return pounds / 2.21;
}

double Weight::getWeightOunces(){
    return pounds * 16;
}

/*
Create a class Weight that stores a weight internally in pounds. 
Create functions setWeightPounds, setWeightKilograms, and setWeightOunces 
that take an input weight in the specified weight scale, convert the weight to pounds if required,
and store that weight in the class's member variable. 
Also, create functions that return the stored weight in pounds, kilograms, and ounce. 
Write a main funcion to test your class.
Use the equations shown next to convert between the weight scales.
    1 pound = 16 ounces
    1 kilogram = 2.21 pounds
*/