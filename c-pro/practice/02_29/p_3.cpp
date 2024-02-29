#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> Q(N);

    for (int i = 0; i < N; i++) {
        int p; cin >> p;
        Q[p-1] =  i+1;
    }

    for (int  e: Q) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}