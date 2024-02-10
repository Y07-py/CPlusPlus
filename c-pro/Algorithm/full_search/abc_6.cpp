#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline bool <class T> chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int m; cin >> m;
    vector<ll> star_x(m);
    vector<ll> star_y(m);
    for (int i = 0; i < m; i++) {
        ll x, y; cin >> x >> y;
        star_x.push_back(x);
        star_y.push_back(y);
    }
    int n; cin >> n;
    vector<ll> map_x(n);
    vector<ll> map_y(n);
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        map_x.push_back(x);
        map_y.push_back(y);
    } 
    for (int i = 0; i < n; i++) {
        ll x = map_x[i] - star_x[0];
        ll y = map_y[i] - star_y[0];
        vector<bool> tf(m, false);
        bool flag = true;
        for (int j = 1; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (star_x[j] + x == map_x[k] && map_y[k] == star_y[j] + y) {
                    tf[j] = true;
                    break;
                } 
            }
            if (tf[j] == false) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << x << " " << y << endl;
            break;
        }
    }
    return 0;
}