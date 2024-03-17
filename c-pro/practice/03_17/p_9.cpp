#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string S; cin >> S;
    string T; cin >> T;
    map<char, int> mps;
    stack<pair<char, int> > sts;
    map<char, int> mpt;
    stack<pair<char, int> > stt;

    int NS = S.size();
    int NT = T.size();

    for (int i = 0; i < NS; i++) {
        if (mps.find(S[i]) == mps.end()) mps[S[i]] = 1;
    }

    for (int i = 0; i < NT; i++) {
        if (mpt.find(T[i]) == mpt.end()) mpt[T[i]] = 1;
    }

    for (int i = 0; i < NS; i++) {
        if (S[i] == S[i+1]) {
            mps[S[i]]++;
        } else {
            sts.push(make_pair(S[i], mps[S[i]]));
            mps[S[i]] = 1;
        }
    }

    for (int i = 0; i < NT; i++) {
        if (T[i] == T[i+1]) {
            mpt[T[i]]++;
        } else {
            stt.push(make_pair(T[i], mpt[T[i]]));
            mpt[T[i]] = 1;
        }
    }

    bool flag = true;
    if (sts.size() != stt.size()) flag = false;
    while (!stt.empty()) {
        pair<char, int> ps = sts.top();
        sts.pop();
        pair<char, int> pt = stt.top();
        stt.pop();

        if (ps.first != pt.first) flag = false;
        else {
            if (ps.second != pt.second) {
                if (ps.second < 2) flag = false;
                if (ps.second > pt.second) flag = false;
            }
        }

        if (!flag) break;
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}