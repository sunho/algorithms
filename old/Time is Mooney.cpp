#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> A(n);
  vector<pair<int,int>> edges(m);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  for (int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    edges[i] = {u,v};
  }
  const ll inf = 1e18;
  vector<ll> dp(n, -inf);
  dp[0] = 0;
  ll ans = 0;
  const int N = 1000;
  for (int t=1;t<=N;t++) {
    vector<ll> nxt(n, -inf);
    for (auto [u,v] : edges) {
      nxt[v] = max(nxt[v], dp[u]+A[v]);
    }
    dp = nxt;
    ans = max(ans, dp[0] - (ll)c*t*t);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
