#include <bits/stdc++.h>
using namespace std;

int main() {
    string N; cin >> N;
    int size = N.length();
    bool flag = true;
    for (int i = 0; i < size-1; i++) {
        int top = N[i] - '0';
        int next = N[i+1] - '0';
        if (top <= next) {
            flag = false;
            break;
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}