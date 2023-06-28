#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    long long ans = K * pow(K-1, N-1);
    cout << ans << endl;
    return 0;
}