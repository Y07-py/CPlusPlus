#include <bits/stdc++.h>
using namespace std;

int main() {
    string A, B, C;
    cin >> A >> B >> C;
    char A_last = A[size(A)-1];
    char B_first = B[0];
    char B_last = B[size(B)-1];
    char C_first = C[0];
    
    if (A_last == B_first && B_last == C_first) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}




