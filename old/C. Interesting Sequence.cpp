#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll n, x;
  cin >> n >> x;
  ll off = 0;
  if (n == x) {
    cout << n << "\n";
    return;
  }
  ll pf = n;
  for (int i=0;i<62;i++) {
    int cnt = __builtin_ctzll(n+off);
    off += 1ll << cnt;
    ll m = n + off;
    pf &= m;
    if (pf == x) {
      cout << m << "\n";
      return;
    }
  }
  cout << -1 << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
