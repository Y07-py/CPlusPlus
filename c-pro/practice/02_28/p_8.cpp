#include <bits/stdc++.h>
#define SIZE 100005

using namespace std;

vector<int> pfact(int x) {
    vector<int> res;
    for (int i = 2; i*i <= x; i++) {
        while (x % i == 0) {
            x /= i;
            res.push_back(i);
        }
    }
    if (x != 1) res.push_back(x);
    return res;
}

int main() {
    int N, M; cin >> N >> M;
    vector<bool> fl(SIZE, true);
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        vector<int> v = pfact(a);
        for (auto &nx: v) {
            if (fl[nx]) {
                for (int j = nx; j < SIZE; j += nx) fl[j] = false;
            }
        }
    }
    vector<int> res;
    for (int i = 1; i <= M; i++) {
        if (fl[i]) res.push_back(i);
    }
    cout << res.size() << endl;
    for (auto &nx: res) {
        cout << nx << endl;;
    }
    return 0;
}