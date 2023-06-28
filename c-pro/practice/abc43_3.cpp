#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> data(N);
    for (int i = 0; i < N; i++) {
        cin >> data.at(i);
    }
    int min_num = *min_element(data.begin(), data.end());
    int max_num = *max_element(data.begin(), data.end());

    if (min_num == max_num) {
        cout << 0 << endl;
        return 0;
    }


    int tmp = 10000000;
    for (int i = min_num; i < max_num; i++) {
        int ans = 0;
        for (int j = 0; j < data.size(); j++) {
            ans += pow((i - data.at(j)), 2); 
        }
        if (ans < tmp) {
            tmp = ans;
        }
    }
    cout << tmp << endl;
}