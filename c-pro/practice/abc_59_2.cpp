#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string A, B;
    cin >> A >> B;
    if (A.size() != B.size())
    {
        if (A.size() > B.size())
        {
            cout << "GREATER" << endl;
        }
        else
        {
            cout << "LESS" << endl;
        }
    }
    else
    {
        if (A > B)
        {
            cout << "GREATER" << endl;
        }
        else if (A < B)
        {
            cout << "LESS" << endl;
        }
        else
        {
            cout << "EQUAL" << endl;
        }
    }
}