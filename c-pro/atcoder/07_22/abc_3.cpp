#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> solve(ll check, ll first, vector<pair<ll, bool> > A, vector<ll> ans) {
    if (A[first].first == check) {
        return ans;
    }
    ll second = A[first].first;
    ans.push_back(second);
    return solve(check, second, A, ans);
}

int main() {
    ll N; cin >> N;
    vector<pair<ll, bool> > A(N);
    ll first;
    for (int i = 0; i < N; i++) {
        ll a; cin >> a;
        A[i].first = a - 1;
        ll next = A[a-1].first;
        
    
    }
    vector<ll> ans;
    vector<ll> result = solve(first, first, A, ans);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i]+1;
    }
    cout << endl;
    return 0;
}