#include <iostream>
using namespace std;

int main(){
    string input;

    while (true){
        cin >> input;
        if (input == "END")
            break;
        
        cout << char(toupper(input[0]));   

        if (cin.get() == '\n')
            cout << ' ' << input << endl;
    }
    
    return 0;
}