#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> data(3);
    for (int i = 0; i < 3; i++) {
        cin >> data.at(i);
    }
    int f_counter = 0;
    int s_counter = 0;

    for (int i = 0; i < 3; i++) {
        if (data.at(i) == 5) {
            f_counter++;
        }
        else if (data.at(i) == 7) {
            s_counter++;
        }
    }
    if (f_counter == 2 && s_counter == 1) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

}