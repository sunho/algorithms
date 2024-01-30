#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector<vector<pair<int,int>>> adj(n);
  vector<int> deg(n);
  for (int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    --u,--v;
    adj[u].push_back({v,w});
  }
  vector<int> dp(n,0);
  for (int i=0;i<n;i++){
    for (auto [v,w] : adj[i]) {
      if (w >= 7) {
        dp[v] = max(dp[v], dp[i] + w + 1);
      } else {
        dp[v] = max(dp[v],dp[i] + w);
      }
    }
  }
  cout << *max_element(begin(dp),end(dp)) + 1 << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
