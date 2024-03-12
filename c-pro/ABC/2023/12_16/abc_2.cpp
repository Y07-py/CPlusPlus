#include <bits/stdc++.h>
using namespace std;

int main() {
    char A1, A2; cin >> A1 >> A2;
    char T1, T2; cin >> T1 >> T2;
    string P = "ABCDE";
    int A1_d = A1 - 'A';
    int A2_d = A2 - 'A';
    int T1_d = T1 - 'A';
    int T2_d = T2 - 'A';
    int A_d = abs(A1_d - A2_d);
    int T_d = abs(T1_d - T2_d);
    if (A_d > 2) A_d = 5 - A_d;
    if (T_d > 2) T_d = 5 - T_d;
    if (A_d == T_d) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}