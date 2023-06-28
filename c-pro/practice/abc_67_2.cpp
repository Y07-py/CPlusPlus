#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i){
        int a; cin >> a;
        A.at(i) = a - 1;
    }
    int counter = 0;
    int ind = 0;
    bool flag = false;
    while (counter < N + 1) {
        counter++;
        int next = A.at(ind);
        ind = next;
        if (next == 1) {
            flag = true;
            break;
        }
    }
    if (flag) {
        cout << counter << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}