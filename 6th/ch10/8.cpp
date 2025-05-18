#include <iostream>
using namespace std;

class Television{
    public:
        Television(): connectiveitySupport(new string[0]) {}
        Television(const string& displayTypeVal, const double& dimensionVal, const string* connectiveitySupportVal, const int& numconnectiveitySupportVal);
        Television(const Television& original);
        void setdisplayType(string displayTypeVal);
        void setdimension(double dimensionVal);
        void setconnectiveitySupport(string *connectiveitySupportVal, int numconnectiveitySupportVal);
        const string& getdisplayType() const;
        const double& getdimension() const;
        const string* getconnectiveitySupport() const;
        const int& getnumconnectiveitySupport() const;
        Television& operator = (const Television& original);
        ~Television();
    private:
        string displayType;
        double dimension;
        string *connectiveitySupport;
        int numconnectiveitySupport;

};

int main(){
    string idisplayType;
    double idimension;
    int inumconnectiveitySupport;
    int numTelevision;

    cout << "Enter the default display type => ";
    cin >> idisplayType;
    cout << "Enter the default dimension => ";
    cin >> idimension;
    cout << "Enter how many types of connection the television support by default => ";
    cin >> inumconnectiveitySupport;
    cin.get();

    string *iconnectiveitySupport = new string[inumconnectiveitySupport];
    for (int i = 0; i < inumconnectiveitySupport; ++i){
        cout << "Enter connection method " << i + 1 << " => ";
        getline(cin, iconnectiveitySupport[i]);
    }

    Television TelevisionDefault(idisplayType, idimension, iconnectiveitySupport, inumconnectiveitySupport);

    cout << "Enter the amount of televisions => ";
    cin >> numTelevision;
    cin.get();
    Television *Televisions = new Television[numTelevision];
    Television temp(TelevisionDefault);
    for (int i = 0; i < numTelevision; ++i){
        cout << "Television " << i + 1 << " Default? (y/n) => ";
        Televisions[i] = temp;
        if (cin.get() == 'n'){
            cin.get();
            cout << "Change display type? (y/n) => ";
            if (cin.get() == 'y'){
                cin.get();
                cout << "Display type => ";
                getline(cin, idisplayType);
            }
            else
                cin.get();
            cout << "Change dimension? (y/n) => ";
            if (cin.get() == 'y'){
                cin.get();
                cout << "Dimension => ";
                cin >> idimension;
                cin.get();
                Televisions[i].setdimension(idimension);
            }
            else
                cin.get();
            cout << "Change connectiveity? (y/n) => ";
            if (cin.get() == 'y'){
                cin.get();
                cout << "Enter how many types of connection the television support => ";
                cin >> inumconnectiveitySupport;
                cin.get();
                iconnectiveitySupport = new string[inumconnectiveitySupport];
                for (int i = 0; i < inumconnectiveitySupport; ++i){
                    cout << "Enter connection method " << i + 1 << " => ";
                    getline(cin, iconnectiveitySupport[i]);
                }
                Televisions[i].setconnectiveitySupport(iconnectiveitySupport, inumconnectiveitySupport);
            }
            else
                cin.get();
        }
        else
            cin.get();
    }

    cout << "Default Television:" << endl
         << "   Display type: " << TelevisionDefault.getdisplayType() << endl
         << "   Dimension: " << TelevisionDefault.getdimension() << endl
         << "   Connetivety Support:" << endl;
    for (int i = 0; i < TelevisionDefault.getnumconnectiveitySupport(); ++i)
        cout << "       " << TelevisionDefault.getconnectiveitySupport()[i] << endl;
    
    for (int i = 0; i < numTelevision; ++i){
        cout << "Television " << i + 1 << ':' << endl
             << "   Display type: " << Televisions[i].getdisplayType() << endl
             << "   Dimension: " << Televisions[i].getdimension() << endl
             << "   Connetivety Support:" << endl;
        for (int j = 0; j < Televisions[i].getnumconnectiveitySupport(); ++j)
            cout << "       " << Televisions[i].getconnectiveitySupport()[j] << endl;
    }

    return 0;
}

Television::Television(const string& displayTypeVal, const double& dimensionVal, const string* connectiveitySupportVal, const int& numconnectiveitySupportVal)
: displayType(displayTypeVal), dimension(dimensionVal), numconnectiveitySupport(numconnectiveitySupportVal) {
    connectiveitySupport = new string[numconnectiveitySupportVal];
    for (int i = 0; i < numconnectiveitySupportVal; ++i) 
        connectiveitySupport[i] = connectiveitySupportVal[i];
}

Television::Television(const Television& original)
: displayType(original.displayType), dimension(original.dimension), numconnectiveitySupport(original.numconnectiveitySupport) {
    connectiveitySupport = new string[original.numconnectiveitySupport];
    for (int i = 0; i < numconnectiveitySupport; ++i){
        connectiveitySupport[i] = original.connectiveitySupport[i];
    }
}

void Television::setdisplayType(string displayTypeVal){
    displayType = displayTypeVal;
}

void Television::setdimension(double dimensionVal){
    dimension = dimensionVal;
}

void Television::setconnectiveitySupport(string *connectiveitySupportVal, int numconnectiveitySupportVal){
    numconnectiveitySupport = numconnectiveitySupportVal;
    delete [] connectiveitySupport;
    connectiveitySupport = new string[numconnectiveitySupport];
    for (int i = 0; i < numconnectiveitySupport; ++i){
        connectiveitySupport[i] = connectiveitySupportVal[i];
    }
}

const string& Television::getdisplayType() const{
    return displayType;
}

const double& Television::getdimension() const{
    return dimension;
}
const string* Television::getconnectiveitySupport() const{
    return connectiveitySupport;
}

const int& Television::getnumconnectiveitySupport() const{
    return numconnectiveitySupport;
}

Television& Television::operator = (const Television& original){
    displayType = original.displayType;
    dimension = original.dimension;
    numconnectiveitySupport = original.numconnectiveitySupport;
    delete [] connectiveitySupport;
    connectiveitySupport = new string[original.numconnectiveitySupport];
    for (int i = 0; i < original.numconnectiveitySupport; ++i)
        connectiveitySupport[i] = original.connectiveitySupport[i];

    return *this;
}

Television::~Television(){
    delete [] connectiveitySupport;
}
/*
    Create a class called Television that has member variables
        displayType          - A string that stores the televsion's display type
        dimension            - A variable of type double that stores the dimension of the television in inches.
        connectiveitySupport - A dynamic array of strings that stores the different connectivity modes supported by the television
    The class should have mutator and accessor functions to set and get the above member variables. 
    Include a constructor that takes arguments of type string, double, and an array of string to assign the three member variables. 
    Also include a copy construction. 
    Embed your class in a test program that reads the input from the user to set displayType, dimension, and connectivitySupport values by default for a television. 
    Your program should then read in input for the number of televisions. 
    Your program should create as many Television objects as required using the copy constructor, and ask the user if customization is required for any television. 
    If so, use the mutator methods to set the valuse accordingly.
*/