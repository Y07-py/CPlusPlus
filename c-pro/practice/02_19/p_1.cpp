#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    set<ll> A;
    set<ll> B;
    vector<ll> AB(N+M);
    for (int i = 0; i < N; i++) {
        ll a; cin >> a;
        A.insert(a);
        AB[i] = a;
    }
    for (int i = N; i < N+M; i++) {
        ll b; cin >> b;
        B.insert(b);
        AB[i] = b;
    }
    sort(AB.begin(), AB.end());
    vector<ll> res_a;
    vector<ll> res_b;
    for (int i = 0; i < N + M; i++) {
        ll item = AB[i];
        if (A.find(item) != A.end()) res_a.push_back(i+1);
        if (B.find(item) != B.end()) res_b.push_back(i+1);
    }
    for (auto &item: res_a) {
        cout << item << " ";
    }
    cout << endl;
    for (auto &item: res_b) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}