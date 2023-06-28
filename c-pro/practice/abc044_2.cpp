#include <bits/stdc++.h>
using namespace std;

int main() {
   string w;
   cin >> w;
   map<char, int> dict;

   for (int i = 0; i < w.size(); i++) {
    dict[w.at(i)] = 0;
   } 
   for (int i = 0; i < w.size(); i++) {
    dict[w.at(i)] += 1;
   }
   for (auto &e: dict) {
    if (e.second % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }
   }
   cout << "Yes" << endl;
}