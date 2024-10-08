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

vector<pair<int, int>> rnd_tree(int n) {
  vector<pair<int, int>> res;
  for (int i = 2; i <= n; i++) {
    res.push_back({i, rnd(1, i - 1)});
  }
  return res;
}

int main() {
  int n = 6; char c = 'A'+rnd(0,5);
  cout << n << " " << c << "\n";
  cout << c;
  for (int i=1;i<n;i++){
    if (rnd(0,1) == 0) {
      cout << (char)('A' + rnd(0,5));
    } else {
      cout << (char)('a' + rnd(0,5));
    }
  }
  cout << "\n";
}
