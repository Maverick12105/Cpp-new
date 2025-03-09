#include <iostream>
using namespace std;

int main(){
    int list_amont, list_num[4];

    cin >> list_amont;
    for (int i = 0; i < list_amont; ++i){
        for (int j = 0; j < 4; ++j){
            cin >> list_num[j];
            cout << list_num[j] << " ";
        }
        if (list_num[3] - list_num[2] == list_num[2] - list_num[1] &&
            list_num[2] - list_num[1] == list_num[1] - list_num[0])
            cout << list_num[3] + list_num[3] - list_num[2] << endl;
        else
            cout << list_num[3] * list_num[3] / list_num[2] << endl;
    }

    return 0;
}