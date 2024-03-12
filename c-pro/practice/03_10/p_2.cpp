#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct inf {
    int right;
    int left;
};

int main() {
    int N; cin >> N;
    string S; cin >> S;
    deque<int> deq;
    deq.push_back(N);
    for (int i = N-1; i > -1; i--) {
        if (S[i] == 'L') {
            deq.push_back(i);
        } else {
            deq.push_front(i);
        }
    }
    for (int i: deq) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}