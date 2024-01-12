#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll d = exgcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

void solve() {
  ll k, c;
  cin >> k >> c;
  ll x, y;
  ll g = exgcd(k, c, x, y);
  if (g != 1) {
    cout << "IMPOSSIBLE"
         << "\n";
  } else {
    ll ans = (y % k + k) % k;
    if (ans * c < k + 1) {
      ans += k;
    }
    if (ans * c < k + 1) {
      ans += k;
    }
    if (ans > (ll)1e9) {
      cout << "IMPOSSIBLE"
           << "\n";
      return;
    }
    cout << ans << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
