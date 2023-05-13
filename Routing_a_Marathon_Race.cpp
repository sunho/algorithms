#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<map<ll, int>> dist(n);
  priority_queue<tuple<int, ll, int>, vector<tuple<int, ll, int>>, greater<>> pq; 
  vector adj(n, vector<int>());
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  for (int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int ans = 1e9;
  int cur = 0;
  vector<int> cnt(n);
  vector<bool> contain(n), vis(n);
  auto dfs = [&](auto self, int u) -> void {
    vector<int> added;
    if (!contain[u]) {
      added.push_back(u);
      contain[u] = true;
      cur += A[u];
    }
    for (int v : adj[u]) {
      cnt[v]++;
      if(!contain[v]) {
        added.push_back(v);
        contain[v] = true;
        cur += A[v];
      }
    }
    vis[u] = true;
    if (u == n-1) {
      ans = min(ans, cur);
    }
    for (int v : adj[u]) {
      if (!vis[v] && cnt[v] < 2) {
        self(self,v);
      }
    }
    vis[u] = false;
    for (int v : adj[u]) {
      cnt[v]--;
    }
    for (int v : added) {
      contain[v] = false;
      cur -= A[v];
    }
  };
  dfs(dfs, 0);
  cout << ans << "\n";
}
