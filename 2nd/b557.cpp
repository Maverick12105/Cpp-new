#include <iostream>
using namespace std;

int main(){
    int T, N, a_i[100], Out;

    cin >> T;
    for (int i = 0; i < T; ++i){
        Out = 0;

        cin >> N;
        if (N < 3){
            cout << Out << endl;
            continue;
        }
        for (int j = 0; j < N; ++j)
            cin >> a_i[j];
        for (int j = 0; j < N; ++j)
            for (int k = j + 1; k < N; ++k)
                for (int l = k + 1; l < N; ++l){
                    if (a_i[j] * a_i[j] + a_i[k] * a_i[k] == a_i[l] * a_i[l] ||
                        a_i[k] * a_i[k] + a_i[l] * a_i[l] == a_i[j] * a_i[j] ||
                        a_i[l] * a_i[l] + a_i[j] * a_i[j] == a_i[k] * a_i[k])
                    ++Out;
                }
        cout << Out << endl;
    } 

    return 0;
}