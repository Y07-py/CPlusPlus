#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; 
    cin >> N >> K;
    bool st[10] = {false};
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        st[x] = true;
    }
    int j = N;
    while (1) {
        string s = to_string(j);
        int len = s.size();
        bool flag = true;
        for (int i = 0; i < len; i++) {
            if (st[s[i] - '0']) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << j << endl;
            return 0;
        }
        j++;
    }
}