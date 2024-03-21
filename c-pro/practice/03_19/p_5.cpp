#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9+7;

map<int, vector<int> > node;

void dfs(int s, set<int> &st) {
    if (st.find(s) != st.end()) return;
    st.insert(s);
    for (int u: node[s]) {
        dfs(u, st);
    }
}

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        a--;
        b--;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    
    set<int> st;
    dfs(0, st);
    cout << *st.rbegin()+1 << endl;
    return 0;
}