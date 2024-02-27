#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<vector<int> > checher;

bool bfs(int sx, int sy, int lx, int ly, char c, vector<string> S) {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<pair<char, pair<int, int> > > que;
    pair<int, int> p = make_pair(sx, sy);
    que.push(make_pair(c, p));
    checher.assign(H, vector<int>(W, 0));
    char current_c;
    
    while (!que.empty()) {
        pair<char, pair<int, int> > item;
        item = que.front();
        que.pop();
        current_c = item.first;
        checher[item.second.first][item.second.second] = 1;
        if (item.second.first == ly && item.second.second == lx) return true;

        for (int i = 0; i < 4; i++) {
            pair<int, int> position = item.second;
            int nx = position.second + dx[i];
            int ny = position.first + dy[i];
            pair<int, int> new_position = make_pair(ny, nx);
            if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
                if (checher[ny][nx]) continue;
                if (current_c == 's') {
                    if (S[ny][nx] == 'n') {
                        que.push(make_pair(S[ny][nx], new_position));
                    } 
                } else if (current_c == 'n') {
                    if (S[ny][nx] == 'u') {
                        que.push(make_pair(S[ny][nx], new_position));
                    }
                } else if (current_c == 'u') {
                    if (S[ny][nx] == 'k') {
                        que.push(make_pair(S[ny][nx], new_position));
                    }
                } else if (current_c == 'k') {
                    if (S[ny][nx] == 'e') {
                        que.push(make_pair(S[ny][nx], new_position));
                    }
                } else if (current_c == 'e') {
                    if (S[ny][nx] == 's') {
                        que.push(make_pair(S[ny][nx], new_position));
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        string s; cin >> s;
        S[i] = s;
    }
    bool ans;
    ans = bfs(0, 0, W-1, H-1, S[0][0], S);
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}