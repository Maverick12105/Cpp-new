#include <iostream>
using namespace std;

int main(){
    int R, C, M, array[10][10], actions[10], array_temp[10][10];

    while (cin >> R >> C >> M){
        for (int i = 0; i < R; ++i)
           for (int j = 0; j < C; ++j)
               cin >> array[i][j];
        for (int i = 0; i < M; ++i)
            cin >> actions[M - 1 - i];

        for (int i = 0; i < M; ++i){
            switch (actions[i]){
                case 0:
                    for (int j = 0; j < R; ++j)
                        for (int k = 0; k < C; ++k)
                            array_temp[k][j] = array[j][C - 1 - k];
                    swap(R, C);
                    for (int j = 0; j < R; ++j)
                        for (int k = 0; k < C; ++k)
                            array[j][k] = array_temp[j][k];
                    break;
                case 1:
                    for (int j = 0; j < R / 2; ++j)
                        for (int k = 0; k < C; ++k)
                            swap(array[j][k], array[R - 1 - j][k]);
                    break;
            }
        }
        
        cout << R << ' ' << C << endl;
        for (int i = 0; i < R; ++i){
            for (int j = 0; j < C; ++j)
                cout << array[i][j] << ' ';
            cout << endl;
        }
    }

    return 0;
}