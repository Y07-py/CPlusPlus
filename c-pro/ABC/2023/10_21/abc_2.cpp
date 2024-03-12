#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<pair<int, int> > array(N);
    for (int i = 0; i < N; i++) {
        int W, X; cin >> W >> X;
        array[i] = make_pair(W, X);
    } 
    int start_time;
    int res = 0;
    for (int i = 0; i < 24; i++) {
        start_time = i;
        int end_time = start_time + 1;
        int tmp = 0;
        for (int j = 0; j < N; j++) {
            int s_time = (start_time + array[j].second) % 24;
            int e_time = (end_time + array[j].second ) % 24;
            if ((9 <= s_time && s_time <= 17) && (10 <= e_time && e_time <= 18)) {
                tmp += array[j].first;
            }
        }
        start_time += 1;
        res = max(res, tmp);
    }
    cout << res << endl;
    return 0;
}