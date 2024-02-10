#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> repunits(3, 1);
    int max_num = 1;
    int base = 10;
    int index = 0;
    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            result += repunits[j];
        }
        if (repunits[index] < max_num) {
            repunits[index] += base;
        }
        if (requires[0] == max_num) {
            max_num += base;
            base *= 10;
            repunits[2] = max_num;
            repunits[1] = 1;
            repunits[0] = 1;
        }
    }
    return 0;
}