#include <iostream>
using namespace std;
#include <string>

class Subscriber{
    public:
        Subscriber(): name(""), numChannels(0), channelList(new string[3]) {}
        friend istream& operator >> (istream& paramIn, Subscriber& param);
        friend ostream& operator << (ostream& paramOut, const Subscriber& param);
        void resetChannels();
        Subscriber& operator = (const Subscriber& param);
        ~Subscriber();
    private:
        string name;
        int numChannels;
        string *channelList;
};

int main(){
    Subscriber a, b;

    cin >> a;
    cout << endl;
    cin >> b;
    cout << endl;

    cout << a << endl;
    b = a;
    a.resetChannels();
    cout << a << endl;
    cout << b << endl;

    return 0;
}

istream& operator >> (istream& paramIn, Subscriber& param){
    delete [] param.channelList;

    cout << "User name => ";
    cin >> param.name;

    cout << "Enter the number of channels => ";
    cin >> param.numChannels;

    cin.get();
    param.channelList = new string[param.numChannels];
    cout << "Enter the list of channels:\n";
    for (int i = 0; i < param.numChannels; ++i){
        cout << "Channel " << i + 1 << " => ";
        getline(cin, param.channelList[i]);
    }

    return paramIn;
}

ostream& operator << (ostream& paramOut, const Subscriber& param){
    cout << "User name: " << param.name << endl;
    cout << "Subscribed channels:" << endl;
    for (int i = 0; i < param.numChannels; ++i)
        cout << param.channelList[i] << endl;

    return paramOut;
}

void Subscriber::resetChannels(){
    numChannels = 0;
    delete [] channelList;
    channelList = new string[0];
}

Subscriber& Subscriber::operator = (const Subscriber& param){
    if (channelList == param.channelList) return *this;

    numChannels = param.numChannels;

    delete [] channelList;
    channelList = new string[numChannels];
    for (int i = 0; i < numChannels; ++i)
        channelList[i] = param.channelList[i];
    
    return *this;
}

Subscriber::~Subscriber(){
    delete [] channelList;
}

/*
    Creat a class named Subscriber that has three member variables:
        name        - A string that stores the name of the subscriber
        numChannels - An integer that tracks how many channels the subscriber subscribes to. 
        channelList - A dynamic array of strings used to store the names of the channels the subscriber subscribes to. 
    Write appropriate constructor(s), mutator, and accessor functions for the class along with the following:

        A function that inputs all values from the user, including the list of channel names. 
        Thus function will have to support input for an arbitrary number of channels. 

        A function that outputs the name and list of all channels. 

        A function that resets the number of channels to 0 and the channelList to an empty list. 

        An overloaded assignment operator that correctly makes a new copy of the list of channels. 

        A destructor that releases all memory that has been allocated. 

    Write a main function that tests all your functions.
*/