#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector adj(n, vector<int>());
  vector<int> nxt(n);
  for (int i=0;i<n;i++){
    cin >> nxt[i];
    nxt[i]--;
    adj[nxt[i]].push_back(i);
  }

  vector<int> vis(n);
  vector<int> cycle_size; 
  vector<int> cycle_id(n,-1);
  auto dfs = [&](auto self, int u) -> void {
    vis[u] = 2;
    int v = nxt[u];
    if (vis[v] == 2) {
      int cur = nxt[v];
      int id = cycle_size.size();
      int size = 1;
      cycle_id[v] = id;
      while(cur != v){
        cycle_id[cur] = id;
        size++;
        cur = nxt[cur];
      }
      cycle_size.push_back(size);
    } else if (vis[v] == 0){
      self(self, v);
    }
    vis[u] = 1;
  };
  for (int i=0;i<n;i++){
    if (!vis[i]) {
      dfs(dfs, i);
    }
  }

  vector<int> dist(n,-1);
  queue<int> q;
  for (int i=0;i<n;i++){
    if (cycle_id[i] != -1) {
      dist[i] = 0;
      q.push(i);
    }
  }
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u]+1;
        q.push(v);
      }
    }
  }

  vector<array<int, 32>> up(n);
  int l = ceil(log2(n));
  for (int i=0;i<l;i++){
    for (int j=0;j<n;j++){
      if (i == 0)
        up[j][i] = nxt[j];
      else
        up[j][i] = up[up[j][i-1]][i-1];
    }
  }

  auto get_up = [&](int u, int k) {
    for (int i=0;i<l;i++){
      if (k & (1 << i)) {
        u = up[u][i];
      }
    }
    return u;
  };

  for (int i=0;i<n;i++){
    if (cycle_id[i] != -1) {
      cout << cycle_size[cycle_id[i]] << " ";
    } else {
      int t = get_up(i,dist[i]);
      cout << cycle_size[cycle_id[t]] + dist[i] << " ";
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
