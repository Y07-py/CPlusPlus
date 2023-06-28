#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, X, Y;
    cin >> N >> K >> X >> Y;
    int total = 0;
    for (int i = 0; i < N; i++) {
        if (i < K) {
            total += X;
        }
        else {
            total += Y;
        }
    }
    cout << total << endl;
}