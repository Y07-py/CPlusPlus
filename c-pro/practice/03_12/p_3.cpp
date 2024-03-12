#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    stack<pair<int, int> > st;
    int total = 0;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        if (st.empty()) {
            st.push(make_pair(a, 1));
            total++;
            cout << total << endl;
            continue;
        }
        if (st.top().first == a) {
            int cnt = st.top().second;
            if (cnt == a-1) {
                st.pop();
                total -= cnt;
            } else {
                st.pop();
                st.push(make_pair(a, cnt+1));
                total++;
            }
        } else {
            st.push(make_pair(a, 1));
            total++;
        }
        cout << total << endl;
    }
    return 0;
}