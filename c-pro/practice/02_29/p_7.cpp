#include <bits/stdc++.h>
using namespace std;
const int inf = 1e5;

vector<vector<char> > rotation(vector<vector<char> > S) {
    int n = S[0].size();
    vector<vector<char> > res(n, vector<char>(n, '.'));
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[j][n - i - 1] = S[i][j];
        }
    }
    return res;
}

bool issame(vector<vector<char> > a, vector<vector<char> > b) {
    int n = a[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < n; j++) {
            if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

vector<vector<char> > normalize(vector<vector<char> > a, int N) {
    vector<vector<char> > n_S(N, vector<char>(N, '.'));
    pair<int, int> d_s = make_pair(inf, inf);
     for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] == '#') {
                d_s.first = min(d_s.first, i);
                d_s.second = min(d_s.second, j);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int dx, dy;
            if (a[i][j] == '#') {
                dx = d_s.first;
                dy = d_s.second;
                n_S[i - dx][j - dy] = a[i][j];
            }
        }
    }
    return n_S;
}

int main() {
    int N; cin >> N; 
    vector<string> S(N);
    vector<string> T(N);
    
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }

    pair<int, int> d_s = make_pair(inf, inf);
    pair<int, int> d_t = make_pair(inf, inf);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] == '#') {
                d_s.first = min(d_s.first, i);
                d_s.second = min(d_s.second, j);
            }
            if (T[i][j] == '#') {
                d_t.first = min(d_t.first, i);
                d_t.second = min(d_t.second, j);
            }
        }
    }

    vector<vector<char> > n_S(N, vector<char>(N, '.'));
    vector<vector<char> > n_T(N, vector<char>(N, '.'));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int dx, dy;
            if (S[i][j] == '#') {
                dx = d_s.first;
                dy = d_s.second;
                n_S[i - dx][j - dy] = S[i][j];
            }
            if (T[i][j] == '#') {
                dx = d_t.first;
                dy = d_t.second;
                n_T[i - dx][j - dy] = T[i][j];
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        if (issame(n_S, n_T)) {
            cout << "Yes" << endl;
            return 0;
        }
        n_S = rotation(n_S);
        n_S = normalize(n_S, N);
    }
    cout << "No" << endl;
    return 0;
}