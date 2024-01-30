#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,k;
  cin >> n >> k;
  vector<set<int>> adj(n);
  for (int i=0;i<n;i++){
    int m;
    cin >> m;
    for (int j=0;j<m;j++){
      int x;
      cin >> x;
      adj[i].insert(x);
      adj[x].insert(i);
    }
  }
  vector<int> vis(n);
  queue<int> q;
  for (int i=0;i<n;i++){
    if (adj[i].size() < k) {
      q.push(i);
      vis[i] = true;
    }
  }
  int ans = 0;
  auto go = [&](int u) {
    int m = adj[u].size() + 1;
    vector<int> V;
    V.push_back(u);
    for (int v : adj[u]) {
      V.push_back(v);
    }
    vector<vector<int>> adj2(m, vector<int>(m));
    for (int i=0;i<m;i++){
      for (int j=0;j<m;j++){
        adj2[i][j] = adj[V[i]].count(V[j]);
      }
    }
    const int M = 1<<m;
    vector<int> dp(M);
    dp[0] = 1;
    for (int msk=1;msk<M;msk++){
      for (int i=0;i<m;i++){
        if (msk>>i&1) {
          int prev = msk ^ (1 << i);
          if (!dp[prev]) continue;
          bool okay = true;
          for (int j=0;j<m;j++){
            if (prev>>j&1) {
              if (!adj2[i][j]) {
                okay = false;
                break;
              }
            }
          }
          if (okay) {
            dp[msk] = true;
            ans = max(ans, __builtin_popcount(msk));
            break;
          }
        }
      }
    }
  };
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    go(u);
    for (int v : adj[u]) {
      adj[v].erase(u);
      if (adj[v].size() < k && !vis[v]) {
        q.push(v);
        vis[v] = true;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
