#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18;

ll sadd(ll x, ll y) {
  return x + y > inf ? inf : x + y;
}

ll smult(ll x, ll y) {
  if (y == 0) return 0;
  if (x > inf/y) 
    return inf;
  return x*y;
}

vector<ll> poly_mult(const vector<ll>& a, const vector<ll>& b) {
  vector<ll> c(a.size()+b.size()-1);
  for (int i=0;i<a.size();i++){
    for (int j=0;j<b.size();j++){
      c[i+j] = sadd(c[i+j], smult(a[i],b[j]));
    }
  }
  return c;
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n; ll k;
  cin >> n >> k;

  vector adj(n, vector<int>());
  for (int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<vector<ll>> dp(n);

  auto dfs = [&](auto self, int u, int p) -> void {
    dp[u] = {0,1};
    for (int v : adj[u]) {
      if (p == v) continue;
      self(self,v,u);
      vector<ll> poly = dp[v];
      poly[0] += 1;
      dp[u] = poly_mult(dp[u], poly);
      if (dp[u].size() > n) dp[u].resize(n+1); 
    }
  };

  dfs(dfs, 0, -1);
  vector<ll> sum(n+1);
  for (int i=0;i<n;i++){
    for (int j=0;j<=n&&j<dp[i].size();j++){
      sum[j] = sadd(sum[j], dp[i][j]);
    }
  }

  for (int i=0;i<=n;i++){
    if (sum[i] >= k) {
      cout << i;
      return 0;
    }
    k -= sum[i];
  }
  cout << -1 << "\n";
}
