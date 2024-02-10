#include <bits/stdc++.h>
#define N (long long)(1e9 + 7)
static const long long MAX = 500000;
using namespace std;

long long factorial[MAX] = {0}, finverse[MAX] = {0},
          inverse[MAX] = {0};

void smodfact() {
  factorial[0] = factorial[1] = 1;
  finverse[0] = finverse[1] = 1;
  inverse[1] = 1;
  for(int i = 2; i < MAX; ++i) {
    factorial[i] = factorial[i - 1] * i % N;
    inverse[i] = N - (inverse[N % i] * (N / i)) % N;
    finverse[i] = finverse[i - 1] * inverse[i] % N;
  }
}

long long calccomb(long long n, long long k) {
  if(n == k && n == 0) return 1;
  return factorial[n] * finverse[k] % N * finverse[n - k] %
         N;
}

long long n, k;

long long solve();

int main() {
  smodfact();
  cin >> n >> k;
  cout << calccomb(n + k - 1, k) << endl;
  return 0;
}
