#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18+7;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<ll> A2(N, 0), A3(N, 0);
    set<int> st;
    for (int i; i < N; i++) {
        int x = A[i];
        while (x % 2 == 0) {
            x /= 2;
            if (A2[i] == inf) {
                A2[i] = 0;
            }
            A2[i]++;
        }
        while (x % 3 == 0) {
            x /= 3;
            if (A3[i] == inf) {
                A3[i] = 0;
            }
            A3[i]++;
        }
        st.insert(x);
    }
    if (st.size() > 1) {
        cout << "-1" << endl;
        return 0; 
    }
    int ans = 0;
    int min2 = *min_element(A2.begin(), A2.end());
    int min3 = *min_element(A3.begin(), A3.end());
    for (int i = 0; i < N; i++) {
        if (A2[i] != inf) ans += A2[i] - min2;
        if (A3[i] != inf) ans += A3[i] - min3;
    }
    cout << ans << endl;
    return 0;
}