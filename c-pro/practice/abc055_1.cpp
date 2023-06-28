#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int total = 0;
    int pay = 0;
    for (int i = 0; i < N; ++i) {
        total += 800;
        if ((i + 1) % 15 == 0) {
            pay += 200;
        }
    }
    cout << total - pay << endl;
    return 0;
}