#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e6

bool is_ok(int key, int value) {
    if (key < value) return true;
    return false;
}

int binary_search(vector<int> c_s, int key) {
    int right = c_s.size();
    int left = -1;

    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (is_ok(key, c_s[mid])) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    int N; cin >> N;
    vector<int> A(N);
    vector<int> tmp_A(N);
    vector<int> memo(INF);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        tmp_A[i] = A[i];
    }
    sort(A.begin(), A.end());
    vector<ll> c_s(N+1, 0);
    for (int i = 0; i < N; i++) {
        c_s[i+1] = c_s[i] + A[i];
    }
    for (int i = 0; i < N; i++) {
        memo[A[i]] = i;
    }
    for (int i = 0; i < N; i++) {
        int index = memo[tmp_A[i]] + 1;
        cout << c_s[N] - c_s[index] << " ";
    }
    cout << endl;
    return 0;
}