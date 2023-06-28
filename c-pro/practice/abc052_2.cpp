#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    int count = 0;
    vector<int> Data(N);
    for (int i = 0; i < S.size(); ++i) {
        if (S.at(i) == 'D') {
            count -= 1;
        }
        else {
            count += 1;
        }
        Data.at(i) = count;
    }
    int answer = *max_element(Data.begin(), Data.end());
    if (answer < 0) {
        cout << 0 << endl;
        return 0;
    }
    cout << answer << endl;
    return 0;
}