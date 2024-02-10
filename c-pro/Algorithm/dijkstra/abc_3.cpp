#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int> > graph;
typedef vector<vector<pair<int, int> > > Graph;
typedef vector<pair<int, int> > pair_v;



int N, K;

void bfs(graph& t, graph town, pair_v p, graph judge) { 
    for (int i = 0; i < N; i++) {
        vector<int> check(N, 0);
        for (int k = 0; k < p[i].second; k++) {
            queue<int> q;
            while (!q.empty()) {
                int to = q.front(); q.pop();
                if (!graph[k][to]) continue;
                if (check[to] != 0) continue;
                t[i].push_back(to);
                check[to] = 1;
                q.push(to);
            }
        }
    }
}

int main() {
    cin >> N >> K;
    pair_v taxi(N);
    graph town(K);
    Graph taxi_graph(N);
    
    for (int i = 0; i < N; i++) {
        int C, R; cin >> C >> R;
        taxi.push_back(make_pair(C, R));
    }

    for (int i = 0; i < K; i++) {
        int A, B; cin >> A >> B;
        A--; B--;
        town[A].push_back(B);
        town[B].push_back(A);
    }


    return 0;
}