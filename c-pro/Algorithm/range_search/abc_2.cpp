#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int MAX = (1 << 21);

vector<int> G[MAX];
list<int> out;
bool V[MAX];
int N;
int indeg[MAX];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    V[s] = true;
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        out.push_back(u);
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            indeg[v]--;
            if (indeg[v] == 0 && !V[v]) {
                V[v] = true;
                q.push(v);
            }
        }
    }
}

void tsort() {
    for (int i = 0; i < N; i++) {
        indeg[i] = 0;
    }
    for (int u = 0; u < N; u++) {
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            indeg[v]++;
        }
    }
    for (int u = 0; u < N; u++) {
        if (indeg[u] == 0 && !V[u]) bfs(u);
    }
    for (list<int>::iterator it = out.begin(); it != out.end(); it++) {
        cout << *it << endl;
    }
}

int main() {

    return 0;
}