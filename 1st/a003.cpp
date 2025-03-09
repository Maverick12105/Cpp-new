#include <iostream>
using namespace std;

int main(){
    int month, day;

    cin >> month >> day;
    switch ((month * 2 + day) % 3)
    {
    case 0:
        cout << "普通";
        break;
    case 1:
        cout << "吉";
        break;
    case 2:
        cout << "大吉";
    default:
        break;
    }

    return 0;
}