#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int M; cin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; i++) cin >> B[i];
    int L; cin >> L;
    vector<int> C(L);
    for (int i = 0; i < L; i++) cin >> C[i];
    set<ll> st;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < L; j++) {
            st.insert(A[i] + C[j]);
        }
    }
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x; cin >> x;
        bool flag = false;
        for (int j = 0; j < M; j++) {
            int b = B[j];
            if (st.find(x - b) != st.end()) {
                flag = true;
            }
        }
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}