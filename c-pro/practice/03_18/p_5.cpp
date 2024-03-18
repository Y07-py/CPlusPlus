#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int AX, AY; cin >> AX >> AY;
    int BX, BY; cin >> BX >> BY;
    int CX, CY; cin >> CX >> CY;
    int DX, DY; cin >> DX >> DY;
    pair<int, int> AB = make_pair(BX - AX, BY - AY);
    pair<int, int> AD = make_pair(DX - AX, DY - AY);
    pair<int, int> DA = make_pair(AX - DX, AY - DY);
    pair<int, int> DC = make_pair(CX - DX, CY - DY);
    pair<int, int> CB = make_pair(BX - CX, BY - CY);
    pair<int, int> CD = make_pair(DX - CX, DY - CY);
    pair<int, int> BC = make_pair(CX - BX, CY - BY);
    pair<int, int> BA = make_pair(AX - BX, AY - BY);

    bool flag1 = true;
    if ((AB.first*AD.second - AB.second*AD.first) < 0) flag1 = false;
    bool flag2 = true;
    if ((DA.first*DC.second - DA.second*DC.first) < 0) flag2 = false;
    bool flag3 = true;
    if ((CB.first*CD.second - CB.second*CD.first) < 0) flag3 = false;
    bool flag4 = true;
    if ((BA.first*BC.second - BA.second*BC.first) < 0) flag4 = false;
    cout << flag1 << flag2 << flag3 << flag4 << endl;
    if (flag1 && flag2 && flag3 && flag4) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}