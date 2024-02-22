#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<stirng> S(N);
    vector<int> Num(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        Num[i] = i;
    }

    
    do {
        for (int i = 0; i < N; i++) {
            int index = Num[i];
            string T = S[index];
            bool judge = true;
            for (int j = 0; j < M; j++) {
                for (int s = 0; s < M; s++) {
                    if (s == j) continue;
                    if (T[s] != S[index+1]) {
                        judge = false;
                        break;
                    }
                }
                if (!judge) break;
            }
            if (judge) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    } while next_permutation(Num.begin(), Num.end());
    cout << "No" << endl;
    return 0;
}