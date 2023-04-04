#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector adj(n, vector<int>());
  for (int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    --a,--b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> max_dist(n);
  auto dfs = [&](int u, int p,  auto&& self) -> int {
    int maxi = 0;
    for (int v : adj[u]) {
      if (v == p) continue;
      maxi = max(maxi, self(v, u, self) + 1);
    }
    return max_dist[u] = maxi;
  };
  dfs(0,-1,dfs);
  vector<int> dp(n);
  auto dfs2 = [&](int u, int p, int hdist, auto&& self) -> int {
    int maxi = 0;
    int maxv = 0;
    int next_maxi = 0;
    for (int v : adj[u]) {
      if (v == p) continue;
      if (maxi < max_dist[v]+1) {
        next_maxi = maxi;
        maxi = max_dist[v]+1;
        maxv = v;
      } else if (next_maxi < max_dist[v]+1) {
        next_maxi = max_dist[v]+1;
      }
    }
    for (int v : adj[u]) {
      if (v == p) continue;
      if (v == maxv) {
        self(v,u, max(hdist+1, next_maxi+1), self);
      } else {
        self(v,u, max(hdist+1, maxi+1), self);
      }
    }
    return dp[u] = max(hdist, max_dist[u]);
  };
  dfs2(0,-1,0,dfs2);
  for (int i=0;i<n;i++){
    cout << dp[i] << " ";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
