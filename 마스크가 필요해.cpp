#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<ll,ll>> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
  }
  vector<pair<ll,ll>> B(m);
  map<ll, ll> cnt;
  for (int i=0;i<m;i++){
    cin >> B[i].first >> B[i].second;
  }
  auto subtract = [&](ll k, ll v) {
    cnt[k] -= v;
    if (cnt[k] == 0) {
      cnt.erase(k);
    }
  };
  sort(begin(B),end(B));
  sort(begin(A),end(A), [](auto a, auto b) {
    return a.second < b.second;
  });
  int ptr = 0;
  int ans = 0;
  for (int i=0;i<n;i++){
    auto [l,r] = A[i];
    while (ptr < m && B[ptr].first <= r) {
      cnt[B[ptr].first] += B[ptr].second;
      ptr++;
    }
    auto it = cnt.lower_bound(l);
    if (it != cnt.end()) {
      ll k = it->first;
      subtract(k, 1);
      ans++;
    }
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
