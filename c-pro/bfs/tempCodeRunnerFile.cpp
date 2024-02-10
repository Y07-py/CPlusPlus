#include <bits/stdc++.h>
using namespace std;

int main() {

  // // 入力
  int H, W;
  cin >> H >> W;
  vector<vector<char> > grid;
  grid.assign(H, vector<char>(W, '.'));

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> grid[i][j];
    }
  }

  // (dh, dw)
  const int dh[4] = {0, 1, 0, -1};
  const int dw[4] = {1, 0, -1, 0};

  // 初期設定
  vector<vector<int> > seen, dist;
  seen.assign(H, vector<int>(W, -1));
  dist.assign(H, vector<int>(W, 0));

  queue<pair<int, int> > que;
  que.push(make_pair(0, 0)); // スタート地点を設定
  dist[0][0] = 1;

  // BFS 開始 (キューが空になるまで探索を行う)
  while (!que.empty()) {
    pair<int, int> v = que.front(); // キューから先頭頂点を取り出す
    que.pop();
    seen[v.first][v.second] = 1;
     // v から辿れる頂点をすべて調べる
    for (int d = 0; d < 4; d++) {
      int nh, nw;
      nh = v.first + dh[d];
      nw = v.second + dw[d];

      if (nw < 0 || nw >= W || nh < 0 || nh >= H) { // はみ出したら、もしくは、既出だったら
        continue;
      }
      if (grid[nh][nw] == '#') {
        continue;
      }
      if (seen[nh][nw] != -1) continue;
      else (seen[nh][nw] == -1) { // 隣が行ったことがない座標だったら
        que.push(make_pair(nh, nw));
        dist[nh][nw] = dist[v.first][v.second] + 1;
      }
    }
  }

  // 結果計算
  int black = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid[i][j] == '#')
        black++;
    }
  }
  if (dist[H - 1][W - 1] == 0) {
    cout << -1 << endl;
  } else {
    cout << H * W - black - dist[H - 1][W - 1] << endl;
  }

  return 0;
}