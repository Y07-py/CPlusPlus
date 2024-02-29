#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void complesion(vector<int>& a) {
    map<int, int> mp;
    int n = a.size();
    int id = 1;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        mp[a[i]] = 0;
    }
    for (auto& itr: mp) {
        itr.second = id++;
    }
    for (int i = 0; i < n; i++) {
        a[i] = mp[a[i]];
    }
}

int main() {
    int H, W, N; cin >> H >> W >> N;
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        ll a, b; cin >> a >> b;
        A[i] = a;
        B[i] = b;
    }
    complesion(A);
    complesion(B);
    for (int i = 0; i < N; i++) {
        cout << A[i] << " " << B[i] << endl;
    }
    return 0;
}