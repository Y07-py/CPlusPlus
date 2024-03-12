#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q; cin >> Q;
    vector<int> Query(Q);
    vector<int> ans(1);
    int index = 0;
    for (int i = 0; i < Q; i++) {
        int a, b; cin >> a >> b;
        if (a == 1) {
            Query.push_back(b);
        } else {
            int size = Query.size();
            ans.push_back(Query[size - b]);
        }
    }
    for (int i = 1; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}