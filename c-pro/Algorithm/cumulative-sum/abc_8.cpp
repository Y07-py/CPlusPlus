#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int> > Graph;

int M, N;
int K;

void solve(Graph& field, int x, int y) {
    field[y+1][x+1] = field[y+1][x] + field[y][x+1] - field[y][x] + 1;
}

int solve_2(Graph field, int x_1, int y_1, int x_2, int y_2) {
    return field[y_2][x_2] - field[y_1][x_2] - field[y_2][x_1] + field[y_1][x_1];
}

int main() {
    cin >> M >> N;
    cin >> K;
    vector<string> Field(M+1);

    for (int i = 0; i < M; i++) {
        string f; cin >> f;
        Field.push_back(f);
    }
    
    vector<vector<int> > dp_J(M+1, vector<int>(N+1, 0));
    vector<vector<int> > dp_O(M+1, vector<int>(N+1, 0));
    vector<vector<int> > dp_I(M+1, vector<int>(N+1, 0));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (Field[i][j] == 'J') {
                solve(dp_J, j, i);
            } else if (Field[i][j] == 'O') {
                solve(dp_O, j, i);
            } else if (Field[i][j] == 'I') {
                solve(dp_I, j, i);
            }
            dp_I[i+1][j+1] = dp_I[i][j+1] + dp_I[i+1][j] - dp_I[i][j];
        }
    }
    
    for (int i = 0; i < K; i++) {
        int x_1, y_1, x_2, y_2;
        cin >> y_1 >> x_1 >> y_2 >> x_2;
        x_1--; 
        y_1--; 
        x_2--; 
        y_2--;
        int res_1 = solve_2(dp_I, x_1, y_1, x_2, y_2);
        int res_O = solve_2(dp_O, x_1, y_1, x_2, y_2);
        int res_J = solve_2(dp_J, x_1, y_1, x_2, y_2);
        cout << res_1 << " "  << res_O << " " << res_J << endl;

    }
    return 0;
}