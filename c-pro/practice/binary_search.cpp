#include <bits/stdc++.h>
using namespace std;

int binary_search(int key, vector<int> &data);
bool is_ok(vector<int> &data, int index, int key);

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> data(N);
    for (int i = 0; i < N; i++) {
        cin >> data.at(i);
    }
    int max_num = *max_element(data.begin(), data.end());
    if (max_num < K) {
        cout << -1 << endl;
        return 0;
    }
    int64_t answer = binary_search(K, data);
    cout << answer << endl;
}

bool is_ok(vector<int> &data, int index, int key) {
    if (data[index] >= key) return true;
    else return false;
}

int binary_search(int key, vector<int> &data) {
    int64_t left = -1;
    int64_t right = data.size();

    while (right - left > 1) {
        int64_t mid = left + (right - left) / 2;
        if (is_ok(data, mid, key)) right = mid;
        else left = mid;
    }
    return right;
}