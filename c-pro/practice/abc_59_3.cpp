#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    vector<ll> A;
    for (int i = 0; i < n; ++i)
    {
        ll a;
        cin >> a;
        A[i] = a;
    }
    ll sum = 0;
    ll ans = 0;
    ll ans_2 = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        sum += A[i];
        if (i % 2 == 0)
        {
            if (sum < 0)
            {
                ans += 1 - sum;
                sum = 1;
            }
            if (sum == 0)
            {
                ans += 1;
                sum = 1;
            }
            if (sum > 0 && sum + A[i + 1] > 0)
            {
                ans += 1 - (sum + A[i + 1]);
                A[i + 1] = -1 - sum;
            }
        }
        else
        {
            if (sum > 0)
            {
                ans += 1 - sum;
                sum = -1;
            }
            if (sum == 0)
            {
                ans += 1;
                sum = -1;
            }
            if (sum < 0 && sum + A[i + 1] < 0)
            {
                ans += 1 - (sum + A[i + 1]);
                A[i + 1] = 1 - sum;
            }
        }
    }
    sum = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        sum += A[i];
        if (i % 2 == 0)
        {
            if (sum > 0)
            {
                ans_2 += 1 - sum;
                sum = -1;
            }
            if (sum == 0)
            {
                ans_2 += 1;
                sum = -1;
            }
            if (sum < 0 && sum + A[i + 1] < 0)
            {
                ans_2 += 1 - (sum + A[i + 1]);
                A[i + 1] = 1 - sum;
            }
        }
        if (i % 2 == 1)
        {
            if (sum < 0)
            {
                ans_2 += 1 - sum;
                sum = 1;
            }
            if (sum == 0)
            {
                ans_2 += 1;
                sum = 1;
            }
            if (sum > 0 && sum + A[i + 1] > 0)
            {
                ans_2 += 1 - (sum + A[i + 1]);
                A[i + 1] = -1 - sum;
            }
        }
    }
    cout << min(ans, ans_2) << endl;
    return 0;
}