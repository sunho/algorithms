#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> prd(n);
  vector adj(n, vector<int>());
  for (int i=0;i<n;i++){
    cin >> prd[i];
    --prd[i];
    adj[prd[i]].push_back(i);
  }
  vector<int> vis(n);
  int next_id = 0;
  vector<int> cycle_id(n,-1);
  vector<int> cycle_num(n);
  vector<int> cycle_size;
  auto dfs = [&](auto self, int u, int depth) -> void {
    vis[u] = 2;
    int v = prd[u];
    if (vis[v] == 2) {
      int cur = prd[v];
      int id = next_id++;
      cycle_id[v] = id;
      cycle_num[v] = 0;
      int i = 1;
      int size = 1;
      while (cur != v) {
        cycle_id[cur] = id;
        cycle_num[cur] = i++;
        cur = prd[cur];
        size++;
      }
      cycle_size.push_back(size);
    } else if (vis[v] == 0) {
      self(self, prd[u], depth+1);
    }
    vis[u] = 1;
  };
  for (int i=0;i<n;i++){
    if(!vis[i]) {
      dfs(dfs, i, 0);
    }
  }
  queue<int> qu;
  vector<int> dist(n,-1);
  for (int i=0;i<n;i++){
    if (cycle_id[i] != -1) {
      qu.push(i);
      dist[i] = 0;
    }
  }
  while (!qu.empty()) {
    int u = qu.front();
    qu.pop();
    for (int v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        qu.push(v);
      }
    }
  }
  
  int l = ceil(log2(n));
  vector<array<int, 32>> down(n);
  for (int i=0;i<l;i++){
    for (int j=0;j<n;j++){
      if (i == 0) {
        down[j][i] = prd[j];
      } else {
        down[j][i] = down[down[j][i-1]][i-1];
      }
    }
  }

  auto get_down = [&](int u, int amount) {
    for (int i=0;i<l;i++){
      if (amount & (1<<i)) {
        u = down[u][i];
      }
    }
    return u;
  };

  while(q--){
    int s,t;
    cin >> s >> t;
    --s,--t;
    if (cycle_id[s] != -1) {
      if (cycle_id[s] == cycle_id[t]) {
        int tid = cycle_id[t];
        cout << (cycle_num[t] - cycle_num[s] + cycle_size[tid]) % cycle_size[tid]   << "\n";
      } else {
        cout << "-1\n";
      }
    } else {
      if (cycle_id[t] == -1 && get_down(s, abs(dist[t] - dist[s])) == t) {
        cout << abs(dist[s] - dist[t]) << "\n";
      } else if (dist[s] != -1 && cycle_id[get_down(s,dist[s])] == cycle_id[t]) {
        int k = get_down(s,dist[s]);
        int tid = cycle_id[t];
        cout << dist[s] + (cycle_num[t] - cycle_num[k] + cycle_size[tid]) % cycle_size[tid]   << "\n";
      } else {
        cout << "-1\n";
      }
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
