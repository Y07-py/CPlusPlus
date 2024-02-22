#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q; cin >> N >> Q;
    priority_queue<int> pq;
    priority_queue<int> a_pq;
    for (int i = 0; i < N; i++) {
        pq.push(-i);
    }
    set<int> done;
    vector<int> res;
    for (int i = 0; i < Q; i++) {
        int num; cin >> num;
        if (num == 1) {
            int p = pq.top();
            pq.pop();
            a_pq.push(p);
        }
        if (num == 2) {
            int x; cin >> x;
            done.insert(x-1);
        }
        if (num == 3) {
            while (-1) {
                int p = -a_pq.top();
                if (done.find(p) != done.end()) {
                    a_pq.pop();
                    pq.push(-p);
                } else {
                    res.push_back(p+1);
                    a_pq.pop();
                    break;
                }
            }
        }
    }
    for (auto &p: res) {
        cout << p << endl;
    }
    return 0;
}