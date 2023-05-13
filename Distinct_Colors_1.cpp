#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> colors(n);
  for (int i=0;i<n;i++){
    cin >> colors[i];
  }

  vector adj(n, vector<int>());
  for (int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> ans(n);
  auto dfs = [&](auto self, int u, int p) -> unordered_set<int> {
    unordered_set<int> cur;
    cur.insert(colors[u]);
    for (int v : adj[u]) {
      if (v == p) continue;
      auto sub = self(self, v, u);
      if (cur.size() < sub.size()) swap(sub,cur);
      for (int v : sub) {
        cur.insert(v);
      }
    }
    ans[u] = cur.size();
    return cur;
  };
  dfs(dfs, 0, -1);
  for (int i=0;i<n;i++){
    cout << ans[i] << " ";
  }
}
