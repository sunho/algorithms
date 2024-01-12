#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll mn, ll mx) {
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
  cout << 1 << "\n";
  int n = 4;
  vector<int> A(n);
  iota(begin(A),end(A),0);
  shuffle(begin(A),end(A),rng);
  cout << n << "\n";
  for (int a : A) {
    cout << a << " ";
  }
  cout << "\n";
}