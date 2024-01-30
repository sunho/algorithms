#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int ilog2(int x) {
  return 32-__builtin_clz(x)-1;
}

void solve() {
  int k, n, m, o;
  cin >> k >> n >> m >> o;
  const ll inf = 1e18;
  const int lv = n/k+1;
  vector<vector<vector<ll>>> adj(lv, vector<vector<ll>>(k,vector<ll>(k, inf)));
  for (int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    adj[u/k][u%k][v%k] = min(adj[u/k][u%k][v%k], (ll)w);
  }
  const int lg = ilog2(lv);
  auto up = vector(lg+1, vector(lv, vector(k, vector(k, inf))));
  for (int j=0;j<lv;j++)
    up[0][j] = adj[j];
  for (int i=0;i<lg;i++) {
    for (int j=0;j<lv-(1<<i);j++) {
      for (int x=0;x<k;x++) {
        for (int y=0;y<k;y++) {
          for (int t=0;t<k;t++) {
            up[i+1][j][x][y] = min(up[i+1][j][x][y], up[i][j][x][t] + up[i][j+(1<<i)][t][y]);
          }
        }
      }
    }
  }
  while (o--) {
    int u,v;
    cin >> u >> v;
    int l1 = u/k, l2 = v/k;
    if (l1 == l2) {
      cout << -1 << "\n";
      continue;
    }
    int cur = l1;
    int del = l2-l1;
    vector<vector<ll>> ts(k, vector<ll>(k, inf));
    bool nw = true;
    for (int i=0;i<=lg;i++) {
      if (del >> i & 1) {
        if (nw) {
          ts = up[i][cur];
          nw = false;
        } else {
          vector<vector<ll>> ts2(k, vector<ll>(k, inf));
          for (int x=0;x<k;x++) {
            for (int y=0;y<k;y++) {
              for (int t=0;t<k;t++) {
                ts2[x][y] = min(ts2[x][y], ts[x][t] + up[i][cur][t][y]);
              }
            }
          }
          ts = ts2;
        }
        cur = cur + (1 << i);
      }
    }
    if (ts[u%k][v%k] == inf) {
      cout << -1 << "\n";
    } else {
      cout << ts[u%k][v%k] << "\n";
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
