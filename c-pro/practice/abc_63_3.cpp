#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Number {
    int value;
    int index;
};

typedef Number Num;

int main() {
    int N; cin >> N;
    vector<int> scores(N);
    for (int i = 0; i < N; ++i) {
        cin >> scores[i];
    }
    vector<Num> base_num(100);
    for (int i = 0; i < N; ++i) {
        if (scores[i]%10 != 0) {
           base_num[i].value = scores[i];
           base_num[i].index = i;
        }
    }
    int total = 0;
    for (int i = 0; i < base_num.size(); ++i) {
        int temp = 0;
        int pre = 0;
        temp = base_num[i].value;
        for (int j = 0; j < N; ++j) {
            if (base_num[i].index == j) continue;
            if ((temp + scores[j]) % 10 != 0) {
                temp += scores[j];
                pre += scores[j];
            } else {
                pre += scores[j];
                if (pre%10 != 0) {
                    temp = pre;
                }
            }
        }
        total = max(total, temp);
    }
    cout << total << endl;
    return 0;
}

