#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int HA, WA; cin >> HA >> WA;
    vector<vector<int> > A(HA, vector<int>(WA));
    for (int i = 0; i < HA; i++) {
        vector<int> st;
        for (int j = 0; j < WA; j++) {
            int a; cin >> a;
            A[i][j] = a;
        }
    }
    int HB, WB; cin >> HB >> WB;
    queue<vector<int> > B;
    for (int i = 0; i < HB; i++) {
        vector<int> st;
        for (int j = 0; j < WB; j++) {
            int b; cin >> b;
            st.push_back(b);
        }
        B.push(st);
    }

    int count = 0;
    int loop = 0;
    int ind = 0;
    while (!B.empty()) {
        vector<int> b = B.front();
        vector<int> a = A[ind];
        int cnt = 0;
        for (int i = 0; i < WB; i++) {
            for (int j = 0; j < WA; j++) {
                if (b[i] == a[j]) {
                    a.erase(a.begin() + j);
                    cnt++;
                    break;
                }
            }
        }
        if (cnt != WB) {
            ind++;
        } else {
            B.pop();
            A.erase(A.begin()+ind);
            count++;
            ind = 0;
        }
        loop++;
        if (loop > 20) {
            break;
        }
        if (ind > HA-1) break;
    }
    if (count == HB) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}