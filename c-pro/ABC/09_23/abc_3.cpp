#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int K; cin >> K;
    vector<ll> array;
    for (int bit = 1; bit < (1 << 10); bit++) {
        int count = 0;
        int res = 0;
        for (int i = 9; i >= 0; i--) {
            if (bit & (1 << i)) {
                res *= 10;
                res += i;
            }
        }
        array.push_back(res);
    }
    sort(array.begin(), array.end());
    cout << array[0] << endl;
}
