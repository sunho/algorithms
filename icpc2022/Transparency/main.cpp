#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 50;
int dist[MAXN][MAXN][2][2];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m, k;
  cin >> n >> m >> k;
  vector adj_up(n, vector(26, -1));
  vector adj_low(n, vector<pair<int, char>>());
  vector<int> dest(n);
  const int inf = 1e8;
  for (int i=0;i<m;i++){
    int u;
    cin >> u;
    --u;
    dest[u] = true;
  }
  for (int i=0;i<k;i++){
    int u,v;
    char c;
    cin >> u >> c >> v;
    --u,--v;
    if ('A' <= c && c <= 'Z') {
      adj_up[u][c-'A'] = v;
    } else {
      adj_low[u].push_back({v,c});
    }
  }

  using PQ = priority_queue<tuple<int,int,int,int,int>, vector<tuple<int,int,int,int,int>>, greater<>>;
  PQ pq;
  pq.push({0,0,0,0,0});

  int ans = inf;
  memset(dist, -1, sizeof(dist));
  while (!pq.empty()) {
    auto [di, u, v, left, done] = pq.top();
    pq.pop();
    if (dist[u][v][left][done] != -1) continue;
    dist[u][v][left][done] = di;
    for (int k=0;k<26;k++){
      if (adj_up[u][k] == -1 || adj_up[v][k] == -1) continue;
      int x = adj_up[u][k], y = adj_up[v][k];
      if (dist[x][y][0][done] == -1) {
        pq.push({di+2, x, y, 0, done});
      }
    }
    if (done && dest[u] && dest[v]) {
      ans = min(ans, di);
    }
    auto update = [&](int u, int v, int left, int done, int ndi) {
      if (dist[u][v][left][done] == -1) {
        pq.push({ndi, u, v, left, done});
      }
    };
    for (auto [x,_] : adj_low[u]) {
      if (done && !left) {
        update(x,v,left,done,di+1);
      }
      if (!done && !left) {
        update(x,x,left,done,di+2);
      }
    }
    for (auto [y,_] : adj_low[v]) {
      if (done) {
        update(u,y,left,done,di+1);
      } else {
        update(u,y,1,1,di+1);
      }
    }
    if (!done) {
      for (auto [x,a] : adj_low[u]) {
        for (auto [y,b] : adj_low[v]) {
          if (a == b) continue;
          update(x,y,0,1,di+2);
        }
      }
    }
  }

  if (ans == inf) cout << -1 << "\n";
  else cout << ans << "\n";
}
