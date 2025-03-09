#include <iostream>
using namespace std;

int main(){
    int num_a, num_b, num_apb;

    while (cin >> num_a >> num_b){
        if (num_b > num_a)
            swap(num_a, num_b);
        while (num_a % num_b != 0){
            num_apb = num_a % num_b;
            num_a = num_b;
            num_b = num_apb;
        }
        cout << num_b << endl;
    }

    return 0;
}