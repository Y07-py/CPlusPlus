#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> P(N);
    vector<int> Q(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < N; i++) cin >> Q[i];
    vector<int> R(N);
    for (int i = 0; i < N; i++)  {
        R[i] = i+1;
    }
    vector<vector<int> > dic;

    do {
        dic.push_back(R);
    } while (next_permutation(R.begin(), R.end()));
    sort(R.begin(), R.end());
    int a = 1;
    int b = 1;
    int cnt = 1;
    for (auto e: dic) {
        bool flag_p = true;
        bool flag_q  = true;
        for (int i = 0; i < N; i++) {
            if (e[i] != P[i]) flag_p = false;
            if (e[i] != Q[i]) flag_q = false;
        }
        if (flag_p) a = cnt;
        if (flag_q) b = cnt;
        cnt++;
    }
    cout << abs(a-b) << endl;
    return 0;
}