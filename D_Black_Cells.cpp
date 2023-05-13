#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> L(n), R(n);
  for (int i=0;i<n;i++) {
    cin >> L[i];
  }
  for (int i=0;i<n;i++){
    cin >> R[i];
  }

  ll inf = 1e18;
  ll ans = inf;
  ll cur = 0;
  ll ones = 0;
  ll cnt = 0;
  bool shift = false;
  int i = 0;
  while (i < n) {
    ll start = L[i];
    cur++;
    while (i < n - 1 && R[i] + 1 == L[i+1]) {
      i++;
    }
    ll mx = (R[i] - start + 1);
    ll mn = clamp(k - cnt, 0ll, mx);
    if (cnt + mn >= k) {
      ll cand = start + cur + mn;
      ans = min(ans, cand);
    }
    if (cnt + mn + ones >= k) {
      ll needed = k - (cnt + mn);
      if (needed > 0) {
        ll cand = start + cur + mn + 2*needed;
        ans = min(ans, cand);
      }
    }
    if (R[i] == start) {
      ones++;
      cur--;
    } else {
      cnt += mx;
      cur++;
    }
    i++;
  }
  if (ans == inf)
    cout << -1 << "\n";
  else
    cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  } 
}
