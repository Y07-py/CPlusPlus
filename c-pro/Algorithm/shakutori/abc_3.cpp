#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> array;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int solve(vector<int> S, int N, int K) {
    int res = 0;
    ll dot = 1;
    int right = 0;
    for (int left = 0; left < N; left++) {
        while (right < N && dot * S[right] <= K) {
            dot *= S[right];
            right++;
        }
        int tmp = right - left;
        chmax(res, tmp);
        if (right == left) right++;
        else dot /= S[left];
    }
    return res;
}

int main() {
    int N, K; cin >> N >> K;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        if (S[i] == 0) {
            cout << N << endl;
            return 0;
        }
    }
    int res = solve(S, N, K);
    cout << res << endl;
    return 0;
}
