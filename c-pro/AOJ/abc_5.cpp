#include <bits/stdc++.h>
using namespace std;

vector<int> a = {0, 3, 4, 5};

bool isOK(int index, int key) {
    if (a[index] >= key) return true;
    else return false;
}

int binary_search(int key) {
    int left = -1;
    int right = (int)a.size();

    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (isOK(mid, key)) right = mid;
        else left = mid;
    }
    return right;
} 


int main() {

    return 0;
}