#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int m;
  cin >> m;
  ll mn = 0, mx = 0;
  map<ll,ll> M;
  map<ll,ll> M2;
  map<ll,ll> M3;
  for (int i=0;i<m;i++){
    ll n, l, r;
    cin >> n;
    cin >> l >> r;
    mn += l;
    mx += r;
    vector<ll> A(n);
    vector<ll> cnt(n);
    for (int j=0;j<n;j++){
      cin >> A[j];
    }
    ll sum = 0;
    for (int j=0;j<n;j++){
      cin >> cnt[j];
      sum += cnt[j];
    }
    for (int j=0;j<n;j++){
      M[A[j]] += min(sum - cnt[j], r);
      M3[A[j]] += max(l-(sum-cnt[j]),0ll);
    }
    for (int j=0;j<n;j++){
      M2[A[j]] += r;
    }
  }
  ll ans = 1e18;
  for (ll sz = mn; sz <= mx; sz++) {
    if (!M.count(sz)) {
      ans = 0;
      break;
    }
    ll cand = max(sz - (mx - M2[sz] + M[sz]), 0ll);
    ans = min(ans, max(cand, M3[sz]));
  }
  cout << ans << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
