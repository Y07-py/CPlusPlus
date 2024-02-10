#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int inf = 100000000;

typedef struct {
    int a;
    int b;
    int c;
} data;

int d, n, ans = 0;
int maxmin[2][65] = {0};
int t[205] = {0};

data ls[205];
int dp[2][205] = {0};

