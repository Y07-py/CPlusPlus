#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Position {
    ll x;
    ll y;
    Position(ll x, ll y):
    x{x}, y{y} {}
};

int main() {
    ll N; cin >> N;
    vector<Position> pos(N);
    for (int i = 0; i < N; ++i) {
        cin >> pos[i].x >> pos[i].y;
    }
    
    return 0;
}