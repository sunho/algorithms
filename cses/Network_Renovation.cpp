#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector adj(n, vector<int>());
  for (int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  vector<int> leafs;

  vector<int> vis(n);
  auto dfs = [&](auto self, int u, int p) -> void {
    vis[u] = 1;
    int cnt = 0;
    int next_id = 0;
    for (int v : adj[u]) {
      if (v == p) continue;
      if (vis[v] == 0) {
        self(self, v, u);
        cnt++;
      } else {
        cnt++;
      }
    }
    if (cnt == 0) {
      leafs.push_back(u);
    }
  };
  dfs(dfs, 0, -1);

  vector<pair<int,int>> ans;
  for (int i=0;i<leafs.size()/2;i++){
    ans.push_back({leafs[i], leafs[i+leafs.size()/2]});
  }
  if (leafs.size() % 2) {
    ans.push_back({leafs.back(), 0});
  }

  
  cout << ans.size() << "\n";
  for (auto [u,v] : ans) {
    cout << u + 1 << " " << v + 1 << "\n";
  }
}
