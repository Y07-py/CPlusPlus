#include <bits/stdc++.h>
using namespace std;
typedfe long long ll;

template<typename T>
vector<T> table(int n, T v) { return vector<T>(n, v); }

template <class... Args>
auto table(int n, Args... args) {
    auto val = table(args...);
    return vector<decltype(val)>(n, move(val));
}

constexpr int dx[6] = [0, 1, 0, 2, 0, 1];
constexpr int dy[6] = {0, 0, 1, 0, 0, 1};
constexpr int dz[6] = {0, 0, 0, 0, 1, 0};


int main() {
    cout << fixed << setprecision(10);
    ll N, D; cin >> N >> D;
    vector<int> cnt;
    for (auto const v: {2, 3, 5}) {
        int c = 0;
        while (d % v == 0) {
            D /= v;
            c++;
        }
        cnt.push_back(c);
    }

    if (D != 1) {
        cout << 0 << endl;
        return 0;
    }

    auto dp = table(cnt[0] + 1, cnt[1] + 1, cnt[2] + 1, 0.0);
    dp[0][0][0] = 1;
    for (int lp = 0; lp < N; lp++) {
        auto nxt = table(cnt[0] + 1, cnt[1] + 1, cnt[2]+ 1, 0.0);
        for (int x = 0; x <= cnt[0]; x++) {
            for (int y = 0; y <= cnt[1]; y++) {
                for (int z = 0; z <= cnt[2]; z++) {
                    for (int i = 0; i < 6; i++) {
                        const int nx = min(cnt[0], x + dx[i]);
                        const int ny = min(cnt[1], y + dy[i]);
                        const int nz = min(cnt[2], z + dz[i]);
                        nxt[nx][ny][nz] += dp[x][y][z] / 6;
                    }
                }
            }
        }
        dp = move(nxt);
    }
    return 0;
}