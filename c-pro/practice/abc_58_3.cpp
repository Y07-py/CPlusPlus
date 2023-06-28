#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> cs(26, 100);
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        vector<int> x(26);
        for (char c : s)
        {
            x[int(c - 'a')]++;
        }
        for (int c = 0; c < 26; ++c)
        {
            cs[c] = min(cs[c], x[c]);
        }
    }
    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < cs[i]; j++)
        {
            cout << char('a' + i);
        }
        cout << '\n';
    }
    return 0;
}