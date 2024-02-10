#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int counter = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) counter++;
        }
        if (counter == 8 && i % 2 == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}