#include <iostream>
using namespace std;

int main(){
    int N, M, xi[20][20], S = 0, N_max[20], divisible = 0, first = 1;

    cin >> N >> M;
    for (int i = 0; i < N; ++i){
        N_max[i] = 0;
        for (int j = 0; j < M; ++j){
            cin >> xi[i][j];
            if (N_max[i] < xi[i][j])
            N_max[i] = xi[i][j];
        }
        S += N_max[i];
    }
    cout << S << endl;
    
    for (int i = 0; i < N; ++i)
        if (S % N_max[i] == 0){
            if (first == 1){
                cout << N_max[i];
                divisible  = 1;
                first = 0;
            }
            else 
                cout << " " << N_max[i];
        }
    if (divisible == 0)
        cout << -1;

    return 0;
}