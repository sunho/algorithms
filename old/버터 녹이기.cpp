#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> A(n);
  for (int i = 0; i < n; i++) {
    int x, h;
    cin >> x >> h;
    A[i] = {x, h / 2};
  }
  auto check = [&](ll t) {
    sort(begin(A), end(A), [&](auto x, auto y) {
      return x.first - min(t, x.second) < y.first - min(t, y.second);
    });
    for (int ptr = 0; ptr < n - 1; ptr++) {
      auto [x, h] = A[ptr];
      ll l = x - min(t, h);
      ll r = x + min(t, h);
      auto [x2, h2] = A[ptr + 1];
      ll l2 = x2 - min(t, h2);
      ll r2 = x2 + min(t, h2);
      if (max(l, l2) <= min(r, r2)) {
        return true;
      }
    }
    return false;
  };
  const ll inf = 1e10;
  ll ng = 0, ok = inf;
  while (ok - ng > 1) {
    ll mid = (ok + ng) / 2;
    if (check(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  if (ok == inf) {
    cout << "forever"
         << "\n";
  } else {
    cout << ok - 1 << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
