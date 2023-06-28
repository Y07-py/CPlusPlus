#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<long long> T(N);
    vector<long long> A(N);

    for (int i = 0; i < N; ++i) {
        int t, a; cin >> t >> a;
        T.at(i) = t;
        A.at(i) = a;
    }

    long long x, y;
    x = T[0], y = A[0];

    long long k1, k2;
    long long l, r, mid;
    long long t1, t2;
    for (int i = 1; i < N; ++i) {
        k1 = T[i] - x;
        k2 = A[i] - y;
        if (k1 == 0 && k2 == 0) continue;

        l = 0;
        r = 10000000000000;
        mid = 0;
        t1 = k1;
        t2 = k2;

        while (r - l > 1) {
            mid = (r + l) / 2;
            k1 = T[i] * mid - x;
            k2 = A[i] * mid - y;

            if (k1 == 0 && k2 == 0) {
                t1 = 0;
                t2 = 0;
                break;
            }
            if (k1 >= 0 && k2 >= 0) {
                t1 = k1;
                t2 = k2;
                r = mid;
            }
            else {
                l = mid;
            }
        }

        x += t1;
        y += t2;
    }

    cout << x + y << endl;

}