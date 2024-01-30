#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Modular Integer
// does arithmetics (mod P) automatically
const int MOD = 998244353;
struct mint {
  int x;
  mint() : x(0) {}
  mint(ll val) : x(val % MOD) { x += (x < 0) * MOD; }
};
mint &operator+=(mint &a, mint b) {
  if ((a.x += b.x) >= MOD)
    a.x -= MOD;
  return a;
}
mint &operator-=(mint &a, mint b) {
  if ((a.x -= b.x) < 0)
    a.x += MOD;
  return a;
}
mint operator*(mint a, mint b) { return mint((ll)a.x * b.x); }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint &operator*=(mint &a, mint b) { return a = a * b; }
mint pow(mint a, ll p) {
  return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mint inv(mint a) { return pow(a, MOD - 2); }
mint operator/(mint a, mint b) { return a * inv(b); }

const int N = 1e6;

mint facts[N + 1];
mint ifacts[N + 1];

mint choose(int n, int k) { return facts[n] * ifacts[n - k] * ifacts[k]; }

void solve() {
  facts[0] = 1;
  for (int i = 1; i <= N; i++) {
    facts[i] = facts[i - 1] * i;
  }
  for (int i = 0; i <= N; i++) {
    ifacts[i] = inv(facts[i]);
  }
  int n;
  cin >> n;
  vector<mint> ans(n);
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      int a;
      cin >> a;
      cnt[a]++;
    }
  }
  for (auto [_, c] : cnt) {
    for (int i = 1; i <= c; i++) {
      ans[i - 1] += choose(c, i);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i].x << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
