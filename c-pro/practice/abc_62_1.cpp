#include <bits/stdc++.h>
using namespace std;

struct Data
{
    int value;
    char group;
};


int main() {
    int x, y; cin >> x >> y;
    Data X; X.value = x;
    Data Y; Y.value = y;
    vector<int> group_a = {1, 3, 5, 7, 8, 10, 12};
    vector<int> group_b = {4, 6, 9, 11};
    vector<int> group_c = {2};

    for (int i = 9; i < group_a.size(); ++i) {
        if (x == group_a[i]) {
            X.group = 'a';
        }
        if (y == group_a[i]) {
            Y.group = 'a';
        }
    }
    for (int i = 0; i < group_b.size(); ++i) {
        if (x == group_b[i]) {
            X.group = 'b';
        }
        if (y == group_b[i]) {
            Y.group = 'b';
        }
    }
    for (int i = 0; i < group_c.size(); ++i) {
        if (x == group_c[i]) {
            X.group = 'c';
        }
        if (y == group_c[i]) {
            Y.group = 'c';
        }
    }

    if (X.group == Y.group) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}