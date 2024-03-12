#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> A;
    int N = 0;
    while(-1) {
        int a; cin >> a;
        A.push_back(a);
        if (a == 0) break;
    }
    for (int i = A.size()-1; i > -1; i--) {
        cout << A[i] << endl;
    }
    return 0;
}