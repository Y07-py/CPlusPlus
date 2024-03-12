#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    for (int i = 100; i <= 919; i++) {
        int num = i;
        int hundled = num / 100;
        num %= 100;
        int ten = num / 10;
        num %= 10;
        int one = num;
        if (hundled * ten == one) {
            if (i >= N) {
                cout << i << endl;
                return 0;
            }
        }
    }
    return 0;
}