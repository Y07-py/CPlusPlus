#include <bits/stdc++.h>
using namespace std;

vector<int> a = {1, 14, 32, 51, 51, 243, 419, 750, 910};

bool is_ok(int index, int key) {
    if (a[index] >= key) return true;
    else return false;
}

int binary_search(int key) {
    int left = -1;
    int right = (int)a.size();

    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (is_ok(mid, key)) right = mid;
        else left = mid;
    }
    return right;
}

int main() {

}