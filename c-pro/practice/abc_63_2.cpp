#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    string alphabets = "abcdefghijklmnopqrstuvwxyz";
    map<char, int> Dict; 
    for (int i = 0; i < alphabets.size(); ++i) {
        Dict[alphabets[i]] = 0;
    }
    for (int i = 0; i < S.size(); ++i) {
        if (Dict[S[i]] > 0) {
            cout << "no" << endl;
            return 0;
        } else {
            Dict[S[i]] += 1;
        }
    }
    cout << "yes" << endl;
    return 0;
}