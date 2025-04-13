#include <iostream>
using namespace std;

class HotDogStand{
    public:
        HotDogStand(int ID, int hotdogSold): ID(ID), hotdogSold(hotdogSold) {SoldTotal += hotdogSold;}
        void JustSold();
        int getSold() const;
        static int getSoldTotal();
    private:
        const int ID;
        int hotdogSold;
        static int SoldTotal;
};

int HotDogStand::SoldTotal = 0;

int main(){
    HotDogStand stand1(1, 3);
    HotDogStand stand2(2, 5);
    HotDogStand stand3(3, 7);
    
    stand1.JustSold();
    stand2.JustSold();
    stand3.JustSold();
    stand2.JustSold();
    stand1.JustSold();

    cout << stand1.getSold() << endl;
    cout << stand2.getSold() << endl;
    cout << stand3.getSold() << endl;
    cout << HotDogStand::getSoldTotal();

    return 0;
}

void HotDogStand::JustSold(){
    ++hotdogSold;
    ++SoldTotal;
}

int HotDogStand::getSold() const{
    return hotdogSold;
}

int HotDogStand::getSoldTotal(){
    return SoldTotal;
}

/*
You operate several hot dog stands distributed throughout town. 
Define a class named HotDogStand that has a member variable for the hot dog stand's ID number 
and a member variable for how many hot dogs the stand sold that day. 
Create a constructor that allows user of the class to initialize both values. 
Also create a function named JustSold that increment the number of hot dogs the stand has sold by one.
This function will be invoked each time the stand sells a hot dog so that you can track the total number of hot dogs sold by the stand. 
Add another function that returns the number of hot dogs sold.
Finally, add a static variable that tracks the total number of hot dogs sold by all hot dog stands 
and a static function that returns the value in this variable.
Write a main function to test your class with at least three hot dog stands that each sell a variety of hot dogs. 
*/