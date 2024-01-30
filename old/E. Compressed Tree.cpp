#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    ans = max(ans, (ll)A[i]);
  }
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int lf1 = -1, lf2 = -1, nlf = 0;
  for (int i = 0; i < n; i++) {
    if (adj[i].size() == 1) {
      if (lf1 == -1) {
        lf1 = i;
      } else if (lf2 == -1) {
        lf2 = i;
      }
    } else {
      nlf = i;
    }
  }
  assert(lf1 != -1 && lf2 != -1);
  const ll inf = 1e18;
  auto dfs = [&](auto &&self, int u, int p) -> ll {
    ll sum = 0;
    vector<ll> rr;
    ll sum2 = 0;
    int cnt2 = 0;
    for (int v : adj[u]) {
      if (p == v)
        continue;
      ll res = self(self, v, u);
      sum += res;
      if (res >= 0) {
        cnt2++;
        sum2 += res;
      }
      rr.push_back(res);
    }
    sort(rbegin(rr), rend(rr));
    ans = max(ans, (ll)A[u]);
    if (rr.size() >= 1) {
      ans = max(ans, A[u] + rr[0]);
    }
    if (rr.size() >= 2) {
      ans = max(ans, rr[0] + rr[1]);
    }
    if (rr.size() >= 3) {
      ans = max(ans, A[u] + rr[0] + rr[1] + rr[2]);
      if (cnt2 >= 3)
        ans = max(ans, A[u] + sum2);
    }
    ll res;
    if (rr.size() == 1) {
      res = max({(ll)A[u], sum, rr[0]});
    } else if (rr.size() >= 2) {
      ll cand = A[u];
      cand = max(cand, rr[0]);
      cand = max(cand, A[u] + rr[0] + rr[1]);
      if (cnt2 >= 2)
        cand = max(cand, A[u] + sum2);
      res = cand;
    } else {
      res = max({(ll)A[u], sum + A[u]});
    }
    return res;
  };
  dfs(dfs, 0, -1);
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
