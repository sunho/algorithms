#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int s,t,m;
  cin >> s >> t >> m;
  vector adj(s+t, vector<int>());
  for (int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  vector vis(t, vector<int>(t, -1));
  for (int i=0;i<s;i++){
    for (int u : adj[i]) {
      u -= s;
      for (int v : adj[i]) {
        v -= s;
        if (u >= v) continue;
        if (vis[u][v] != -1) {
          cout << u + s + 1 << " " << vis[u][v] + 1 << " " << v + s + 1 << " " << i + 1 << "\n";
          return 0;
        }
        vis[u][v] = i;
      }
    }
  }
  cout << -1 << "\n";
}
