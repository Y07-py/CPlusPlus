#include <bits/stdc++.h>
using namespace std;


int main() {
    int N; cin >> N;
    string S; cin >> S;
    for (int i = 0; i < S.length()-2; i++) {
        if (S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C') {
            cout << i +1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}