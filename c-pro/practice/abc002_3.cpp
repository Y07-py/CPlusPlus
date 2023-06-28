#include <bits/stdc++.h>
using namespace std;

int main() {
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    int ab_vec_x = xb - xa;
    int ab_vec_y = yb - ya;
    int ac_vec_x = xc - xa;
    int ac_vec_y = yc - ya;
    cout << fixed << setprecision(3);
    cout << (double)abs(ab_vec_x * ac_vec_y - ab_vec_y * ac_vec_x) / 2 << endl;
    return 0;
}