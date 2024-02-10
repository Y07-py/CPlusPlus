#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1 << 20

int N, M, K, S;
int P, Q;
bool zombie[101010];
bool danger[101010];
int dist[101010];
vector<int> E[101010];

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

void bfs() {
    queue<int> que;

    for (int i = 0; i < N; i++) {
        if (zombie[i]) {
            dist[i] = 0;
            que.push(i);
        }
        else dist[i] = -1;
    }

    while (!que.empty()) {
        int cu = que.front(); que.pop();

        for (auto& to: E[cu]) {
            dist[to] = dist[cu] + 1;
            que.push(to);
        }
    }
    for (int i = 0; i < N; i++) {
        if (1 <= dist[i] && dist[i] <= S) {
            danger[i] = true;
        }
    }
}

bool vis[101010];
ll D[101010];

ll dijikstr() {
    for (int i = 0; i < N; i++) {
        D[i] = INF;
        vis[i] = false;
    }
    priority_queue<pair<int, ll> > pq;
    D[0] = 0;
    pq.push(make_pair(0,0));

    while (!pq.empty()) {
        pair<int, ll> p = pq.top();
        pq.pop();
        int u = p.first;
        ll cost = (-1) * p.second;
        if (u == N-1) {
            if (danger[u]) return cost - Q;
            else return cost - P;
        }
        if (vis[u]) continue;
        vis[u] = 1;

        for (auto& to: E[u]) {
            if (zombie[to]) continue;
            ll cost2 = cost;
            if (danger[to]) cost2 += Q;
            else cost2 += P;
            if (chmin(D[to], cost2)) pq.push(make_pair(to, (-1)*D[to]));
        }
    }
    return -1;
}

int main() {
    cin >> N >> M >> K >> S;
    cin >> P >> Q;
    for (int i = 0; i < K; i++) {
        int c; cin >> c;
        c--;
        zombie[c] = true;
    }
 
    for (int i = 0; i < M; i++) {
        int A, B; cin >> A >> B;
        A--, B--;
        E[A].push_back(B);
        E[B].push_back(A);
    }
    bfs();
    cout << dijikstr() << endl;
    cout << "Hello" << endl;

    return 0;
}