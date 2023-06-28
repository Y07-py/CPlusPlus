#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> city(N);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        city[a-1].push_back(b-1);
        city[b-1].push_back(a-1);
    }
    for (int i = 0; i < N; ++i) {
        cout << size(city[i]) << endl;
    }
    return 0;
}