#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll rnd(ll mn, ll mx) {
  static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<ll> gen(mn, mx);
  return gen(rng);
}

vector<int> rnd_array(int n, int mn, int mx) {
  int in = 0;
  vector<int> A(n);
  int m = mx - mn + 1;
  for (int i = 0; i < m && in < n; ++i) {
    int rm = m - i;
    int rn = n - in;
    if (rnd(0, rm - 1) < rn)
      A[in++] = i;
  }
  assert(in == n);
  return A;
}

int main() {
  int n = rnd(1, 50);
  n *= 2;
  int k = rnd(1, n / 4);
  k *= 2;
  cout << n << " " << k << "\n";
}
