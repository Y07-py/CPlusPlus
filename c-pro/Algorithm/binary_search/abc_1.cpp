#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1010101010;

int d, n, m;

bool isOk(int dis, int &res) {
    if (dis < res) {
        res = dis;
        return true;
    }
    return false;
}

int binary_search(vector<int> data, int n, int order, int res) {
    int left = -1;
    int right = n;
    while (right - left > 1) {
        int mid = left + (right - left)/2;
        int dis = abs(data[mid] - order);
        if (isOk(dis, res)) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    cin >> d >> n >> m;
    vector<int> shops(n+1);
    ll ans = 0;

    for (int i = 1; i < n; i++) {
        cin >> shops[i];
    }
    shops[n] = d;
    sort(shops.begin(), shops.end());
    int res = MAX;
    for (int i = 0; i < m; i++) {
        int order; cin >> order;
        int right;
        right = binary_search(shops, n, order, res);
        ll tmp = abs(shops[right] - order);
        if (right > 0) {
             if (tmp > abs(shops[right - 1] - order)) tmp = abs(shops[right-1] - order);
        }
        res = MAX;
        ans += tmp;
    }
    
    cout << ans << endl;
    return 0;
}