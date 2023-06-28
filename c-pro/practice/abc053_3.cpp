#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll X; cin >> X;
    ll answer = (X / 11) * 2;
    X = X % 11;
    if (1 <= X && X <= 6) {
        answer += 1;
    }
    else if (X == 0) {
        answer = answer;
    }
    else if (7 <= X && X <= 10){
        answer += 2;
    }
    
    cout << answer << endl;

    return 0;
}