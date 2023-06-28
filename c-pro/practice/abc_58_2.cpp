#include <bits/stdc++.h>
using namespace std;

int main()
{
    string O, E;
    cin >> O >> E;
    int size = O.size() + E.size();
    int ind_o = 0;
    int ind_a = 0;
    string ans;
    for (int i = 0; i < size; ++i)
    {
        if (i % 2 == 0)
        {
            ans += O[ind_o];
            ind_o++;
        }
        else
        {
            ans += E[ind_a];
            ind_a++;
        }
    }
    cout << ans << endl;
    return 0;
}