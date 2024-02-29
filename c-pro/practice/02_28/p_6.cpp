#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int permutation(int n) {
    if (n == 1) return n;
    return n * permutation(n-1);
}

int main() {
    string S; cin >> S;
    int K; cin >> K;
    int cnt = 0;
    sort(S.begin(), S.end());
    do {
        cnt++;
        if (cnt == K) {
            cout << S << endl;
            break;
        }
    } while (next_permutation(S.begin(), S.end()));
    return 0;
}