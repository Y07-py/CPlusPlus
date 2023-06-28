#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W; cin >> H >> W;
    vector<string> pixels[H];
    for (int i = 0; i < H; ++i) {
        string a; cin >> a;
        pixels[i].push_back(a);
    }
    int width = W + 2;
    int ind = 0;
    for (int i = 0; i < H+2; ++i) {
        if (i == 0 || i  == H+1) {
            for (int j = 0; j < width; ++j) {
                cout << '#';
            } 
        }
        else  {
            int index = 0;
            for (int j = 0; j < width; ++j) {
                if (j == 0 || j == H+1) {
                cout << '#';
                } else {
                    cout << pixels[ind][index];
                    index++;
                    }
                }
                ind++;
            }
        cout << endl;
    }

    return 0;
}