#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    int res = 0;
    int checker[1000] = {0};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int t = 0; t < 10; t++) {
                int index = 0;
                string pw = to_string(i) + to_string(j) + to_string(t);
                for (int s = 0; s < N; s++) {
                    if (S[s] - '0' == pw[index] - '0') {
                        index++;
                        if (checker[stoi(pw)] == 0) checker[stoi(pw)]++;
                        else continue;;
                        res++;
                    }
                }
    
            }
        }
    }
    cout << res << endl;
    return 0;
}