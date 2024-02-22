#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool judge(int value) {
    if (value) return true;
    return false;
}

int main() {
    int N; cin >> N;
    int right = N;
    int left = -1;
    while (right - left > 1) {
        int mid = left  - (left - right)/2;
        cout << "?" << " " << mid << endl;
        int s; cin >> s;
        if (s) right = mid;
        else left = mid;
    }
    cout << right << endl;
    return 0;
}