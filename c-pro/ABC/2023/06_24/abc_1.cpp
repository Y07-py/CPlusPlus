#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int total = 0;
    for (int i = 0; i < (N * 7); ++i) {
        int a; cin >> a;
        total += a;
        
        if ((i+1) % 7 == 0) {
            cout << total << endl;
            total = 0;
        }
    }
    return 0;
}