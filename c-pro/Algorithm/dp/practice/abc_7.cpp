#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int mod = 10000;

int main() {
    int N, K; cin >> N >> K;
    vector<int> AB(N, -1);
    for (int i = 0; i < K; i++) {
        int a, b; cin >> a >> b;
        a--;
        AB[a] = b-1;
    }

    vector<vector<int> > dp(N + 1, vector<int>(3));

    for (int i = 0; i < N; i++) {
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                vector<int> cs = {0, 1, 2};
                if (AB[i] >= 0) cs = {AB[i]};
            }
        }
    }
    return 0;
}