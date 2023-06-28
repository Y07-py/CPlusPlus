#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    vector<string> data(N);
    for (int i = 0; i < N; i++) {
        cin >> data.at(i);
    }
    string tmp;
    for (int i = 0; i < N-1; i++) {
        tmp = data.at(i);
        for (int j = i+1; j < N; j++) {
            if (tmp > data.at(j)) {
                data.at(i) = data.at(j);
                data.at(j) = tmp; 
                tmp = data.at(i);
            }
        }
    }
    string answer;
    for (int i = 0; i < N; i++) {
        answer += data.at(i);
    }
    cout << answer << endl;
}