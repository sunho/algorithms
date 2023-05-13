#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;

void solve() {
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

  map<int,int> leafs;
  vector<int> levels(n);

  auto dfs = [&](auto self, int u, int p, int level) -> void {
    int cnt = 0;
    levels[u] = level;
    for (int v : adj[u]) {
      if (v == p) continue;
      self(self, v, u, level + 1);
      cnt++;
    }
    if (cnt == 0) {
      leafs[p]++;
    }
  };
  dfs(dfs, 0, -1, 0);
  
  priority_queue<pair<int,int>> pq;
  for (auto [u, cnt] : leafs) {
    pq.push({cnt,u });
  }
  if (pq.size() == 1) {
    auto [cnt, u] = pq.top();
    if (levels[u] <= 1) {
      cout << -1 << "\n";
      return;
    }
  }
  int ans = 0;
  while (pq.size() >= 2) {
    auto [cnt, u] = pq.top();
    pq.pop();
    auto [cnt2, v] = pq.top();
    pq.pop();
    cnt--,cnt2--;
    ans++;
    if (cnt != 0) {
      pq.push({cnt, u});
    }
    if (cnt2 != 0) {
      pq.push({cnt2, v});
    }
  }
  if (pq.size())
    ans += pq.top().first;
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
