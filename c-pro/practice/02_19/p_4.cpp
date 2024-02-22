#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int Q; cin >> Q;
    vector<vector<int> > boxes(N);
    map<int, set<int> > box_num;
    for (int q = 0; q < Q; q++) {
        int num; cin >> num;
        if (num == 1) {
            int i, j; cin >> i >> j;
            boxes[j-1].push_back(i);
            box_num[i].insert(j);
        } else if (num == 2) {
            int i; cin >> i;
             sort(boxes[i-1].begin(), boxes[i-1].end());
            for (int j = 0; j < boxes[i-1].size(); j++) {
                cout << boxes[i-1][j] << " ";
            }
            cout << endl;
        } else {
            int i; cin >> i;
            for (auto item = box_num[i].begin(); item != box_num[i].end(); item++) {
                cout << *item << " ";
            }
            cout << endl;
        }
    }
    return 0;
}