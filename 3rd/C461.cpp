#include <iostream>
using namespace std;

int main(){
    int a, b, result, flag = 0;
    
    cin >> a >> b >> result;
        flag = 0;

    if ((bool(a) and bool(b)) == bool(result)){
        cout << "AND" << endl;
        flag = 1;
    }
    if ((bool(a) or bool(b)) == bool(result)){
        cout << "OR" << endl;
        flag = 1;
    }
    if ((bool(a) xor bool(b)) == bool(result)){
        cout << "XOR" << endl;
        flag = 1;
    }
    
    if (flag == 0)
        cout << "IMPOSSIBLE";

    return 0;
}