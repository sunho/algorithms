#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  int r,b,y;
  cin >> r >> b >> y;
  vector<bool> used(m);
  vector<int> edges(m);
  map<char, int> conv = {
    {'X', 0b000},
    {'R', 0b100},
    {'B', 0b010},
    {'Y', 0b001},
    {'P', 0b110},
    {'O', 0b101},
    {'G', 0b011}
  };
  vector adj(n, vector<pair<int,int>>());
  for (int i=0;i<m;i++) {
    int u,v;
    cin >> u >> v;
    --u,--v;
    char c;
    cin >> c;
    if (c == 'X') {
      used[i] = true;
    }
    edges[i] = conv[c];
    adj[u].push_back({v,i});
    adj[v].push_back({u,i});
  }
  --r,--b,--y;

  bool vis[100][100][100];
  memset(vis, 0, sizeof(vis));
  auto dfs = [&](auto self, array<int,3> cur) -> void {
    if (vis[cur[0]][cur[1]][cur[2]]) return;
    vis[cur[0]][cur[1]][cur[2]] = true;
    auto visit = [&](int color, int v) {
      array<int,3> next;
      for (int z=0;z<3;z++){
        if (color & (1 << z)) {
          next[z] = v;
        } else {
          next[z] = cur[z];
        }
      }
      self(self, next);
    };
    for (int i=0;i<3;i++){
      int mask = 0;
      for (int j=0;j<3;j++){
        if (cur[i] == cur[j]) {
          mask |= (1<<j);
        }
      }
      for (auto [v, k] : adj[cur[i]]) {
        int color = edges[k];
        if (color == 0) {
          for (int m=1;m<(1<<3);m++){
            if ((mask & m) == m) {
              visit(m, v);
            }
          }
          continue;
        }
        if ((mask & color) == color) {
          used[k] = true;
          visit(color, v);
        }
      }
    }
  };
  dfs(dfs, {y,b,r});
  for (int i=0;i<m;i++){
    if (!used[i]){
      cout << 0;
      return 0;
    }
  }
  cout << 1;
}
