#include <bits/stdc++.h>
using namespace std;
static const int MAX = (1 << 30);

vector<int> isprime(101010, 1);

void solve(int n) {
    isprime[0] = 0;
    isprime[1] = 0;

    for (int i = 2; i <= pow(n, 0.5); i++) {
        if (isprime[i]) {
            for (int j = 2; j * i <= n; j++) {
                isprime[j * i] = 0;
            }
        }
    }
}

int main() {
    int Q; cin >> Q;
    vector<pair<int, int> > array(Q);
    for (int i = 0; i < Q; i++) {
        int l, r; cin >> l >> r;
        array[i] = make_pair(l, r);
    }
    solve(101010);
    vector<int> A(101010, 0);
    vector<int> B(101010, 0);
    for (int i = 1; i <= 101010; i++) {
        if (isprime[i] && isprime[(i + 1) / 2]) {
            A[i] = 1;
        }
    }
    for (int i = 2; i <= 101010; i++) {
        B[i] = B[i-1] + A[i];
    }
    for (int i = 0; i < Q; i++) {
        pair<int, int> area = array[i];
        int ans = B[area.second] - B[area.first-1];
        cout << ans << endl;
    }
    return 0;
}