#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> deg(n);
  vector<vector<int>> adj(n);
  for (int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  int timer = 0;
  vector<int> time(n);
  auto dfs = [&](auto&& self, int u, int p) -> void {
    time[u] = timer++;
    for (int v : adj[u]) {
      if (v == p) continue;
      self(self, v, u);
    }
  };
  int root = 0;
  vector<int> leafs;
  for (int i=0;i<n;i++){
    if (deg[i] == 1) {
      leafs.push_back(i);
    } else {
      root = i;
    }
  }
  dfs(dfs, root, -1);
  sort(begin(leafs),end(leafs),[&](int i, int j) {
    return time[i] < time[j];
  });
  cout << (leafs.size() + 1)/2 << "\n";
  int m = leafs.size();
  for (int i=0;i<(m+1)/2;i++) {
    cout << leafs[i]+1 << " " << leafs[i+m/2]+1 << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
