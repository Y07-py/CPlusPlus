#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int M, N; cin >> M >> N;
    int K; cin >> K;
    vector<string> Field(M);
    vector<vector<int> > Order(K, vector<int>(4));
    vector<vector<int> > CS_I(M+1, vector<int>(N+1, 0));
    vector<vector<int> > CS_J(M+1, vector<int>(N+1, 0));
    vector<vector<int> > CS_O(M+1, vector<int>(N+1, 0));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Field[i][j];
        }
    }
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> Order[i][j];
        }
    }

    for (int i = 0; i < M+1; i++) {
        for (int j = 0; j < N+1; j++) {
            if (Field[i][j] == 'I') {
                CS_I[i+1][j+1] = CS_I[i][j+1] + CS_I[i+1][j] - CS_I[i][j] + 1;
            } else if (Field[i][j] == 'O') {
                CS_O[i+1][j+1] = CS_O[i][j+1] + CS_O[i+1][j] - CS_O[i][j] + 1;
            } else {
                CS_J[i+1][j+1] = CS_J[i][j+1] + CS_J[i+1][j] - CS_J[i][j] + 1;
            }
        }
    }

    for (int i = 0; i < K; i++) {
        int x_2, y_2, x_1, y_1;
        x_2 = Order[i][2];
        y_2 = Order[i][3];
        x_1 = Order[i][0];
        y_1 = Order[i][1];
        cout << CS_J[y_2][x_2] - CS_J[y_1][x_2] - CS_J[y_2][x_1] + CS_J[y_1][x_1] << endl;
    }


    return 0;
}