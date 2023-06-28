#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    stack<int> A;
    A.push(S[0]);
    A.push(S[1]);
    for (int i = 2; i < S.size(); ++i) {
        if (S[i] == '+') {
            int a = A.top();
            A.pop();
            int b = A.top();
            A.pop();
            A.push(a+b);
        } else if (S[i] == '-') {
            int a = A.top();
            A.pop();
            int b = A.top();
            A.pop();
            A.push(a - b);
        } else if (S[i] == '*') {
            int a = A.top();
            A.pop();
            int b = A.top();
            A.pop();
            A.push(a*b);
        } else {
            int a = A.top();
            A.pop();
            int b = A.top();
            A.pop();
            A.push(a / b);
        }
    }
    cout << A.top() << endl;
    return 0;
}