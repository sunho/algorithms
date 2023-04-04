#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector adj(n, vector<pair<int,int>>());
  for (int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back({v,i});
    adj[v].push_back({u,i});
  }
  map<int,int> cnt;
  vector<int> A(n);
  set<int> avail;
  int mx = 0;
  for (int i=0;i<n;i++){
    cin >> A[i];
    cnt[A[i]]++;
    if (cnt[A[i]] >= 3) {
      avail.insert(A[i]);
    }
    if (cnt[A[i]] >= 2) {
      mx = max(mx, A[i]);
    }
  }
  if (mx == 0) {
    for (int i = 0;i<n-1;i++){
      cout << 0 << "\n";
    }
    return 0;
  }
  vector<int> mx_idx;
  for (int i=0;i<n;i++){
    if (cnt[A[i]] != 2) {
      A[i] = 0;
    } else {
      avail.insert(A[i]);
    }
    if (mx == A[i]) {
      mx_idx.push_back(i);
    }
  }
  if (mx_idx.empty()) {
    for (int i = 0;i<n-1;i++){
      cout << mx << "\n";
    }
    return 0;
  }
  vector<int> prd(n);
  auto dfs = [&](auto self, int u, int p) -> void {
    for (auto [v,_] : adj[u]) {
      if (v == p) continue;
      prd[v] = u;
      self(self, v,u);
    }
  };
  dfs(dfs, mx_idx[0], -1);
  vector<int> ans(n-1);
  int cur = mx_idx[1];
  set<int> path;
  while (cur != mx_idx[0]) {
    path.insert(cur);
    cur = prd[cur];
  }
  map<int,int> cnt2;
  auto dfs2 = [&](auto self, int u, int p) -> void {
    for (auto [v, id] : adj[u]) {
      if (v == p) continue;
      if (path.count(v)) {
        self(self, v, u);
      }
      ans[id] = avail.empty() ? 0 : *--avail.end();
    }
    for (auto [v, id] : adj[u]) {
      if (v == p) continue;
      if (!path.count(v)) {
        ans[id] = mx;
        self(self, v, u);
      }
    }
    cnt2[A[u]]++;
    if (cnt2[A[u]] == 1) {
      avail.erase(A[u]);
    } else {
      avail.insert(A[u]);
    }
  };
  dfs2(dfs2, mx_idx[0], -1);
  for (int i=0;i<n-1;i++){
    cout << ans[i] << "\n";
  }
}
