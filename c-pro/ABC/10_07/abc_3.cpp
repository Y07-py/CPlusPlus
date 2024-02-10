#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }
    vector<int> players(N, 0);
    for (int i = 0; i < N; i++) {
        string S; cin >> S;
        for (int j = 0; j < M; j++) {
            if (S[j] == 'o') {
                players[i] += A[j];
            }
        }
        players[i] += (i + 1);
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) {
        int player = players[i];
        int diff = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (player <= players[j]) {
                diff = max(diff, players[j] - player);
            }
        }
        int counter = 0;
        if (diff == 0) {
            cout << counter << endl;
            continue;
        }
        for (int j = M - 1; j > -1; j--) {
            diff -= A[j];
            counter += 1;
            if (diff <= 0) {
                cout << counter << endl;
                break;
            }
        }
    }
    return 0;
}