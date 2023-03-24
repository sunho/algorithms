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

  vector<int> prt(n);
  vector<int> order;
  auto dfs = [&](auto self, int u, int p) -> void {
    prt[u] = p;
    for (int v : adj[u]) {
      if (v == p) continue;
      self(self, v, u);
    }
    order.push_back(u);
  };
  dfs(dfs, 0, -1);
  vector<int> cnt(n);
  vector<ll> path(n);
  for (int u : order) {
    cnt[u] = 1;
    ll cur_sum = 0;
    for (int v : adj[u]){
      if (v == prt[u]) continue;
      cnt[u] += cnt[v];
      path[u] += cnt[v] + path[v];
    }
  }
  vector<ll> ans(n);
  auto dfs2 = [&](auto self, int u, int p, ll parent_path, int parent_cnt) -> void {
    ll sum = 0;
    for (int v : adj[u]) {
      if (v == p) continue;
      sum += path[v];
      ll except = path[u] - path[v] - cnt[v];
      self(self, v, u, parent_path + except + parent_cnt, parent_cnt + cnt[u]-cnt[v]);
    }
    ans[u] = sum + parent_path + n - 1;
  };
  dfs2(dfs2, 0, -1, 0, 0);
  for (int i=0;i<n;i++){
    cout << ans[i] << " ";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
