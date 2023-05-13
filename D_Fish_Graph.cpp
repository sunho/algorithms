#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector adj(n, vector<int>());
  vector<int> deg(n);
  for (int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    deg[u]++, deg[v]++;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  auto find = [&](int s, vector<int>& cycle) {
    vector<int> vis(n);
    vector<int> prd(n, -1);
    queue<pair<int,int>> q;
    q.push({s,-1});
    vector<int> dist(n,-1);
    dist[s] = 0;
    while (!q.empty()) {
      auto [u,p] = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (v == p) continue;
        if (dist[v] == -1) {
          dist[v] = dist[u]+1;
          prd[v] = u;
          q.push({v,u});
        } else {
          for (int cur = v; cur != s; cur = prd[cur]) {
            cycle.push_back(cur);
          }
          cycle.push_back(s);
          reverse(begin(cycle), end(cycle));
          for (int cur = u; cur != s; cur = prd[cur]) {
            cycle.push_back(cur);
          }

          reverse(begin(cycle), end(cycle));
          return true;
        }
      }
    }
    return false;
  };

  for (int i=0;i<n;i++){
    if (deg[i] >= 4) {
      vector<int> cycle;
      set<int> vert;
      if (find(i, cycle)) {
        vector<pair<int,int>> ans;
        for (int i=0;i<cycle.size();i++) {
          vert.insert(cycle[i]);
          ans.push_back({cycle[i], cycle[(i+1)%cycle.size()]});
        }
        int added = 0;
        for (int v : adj[i]) {
          if (!vert.count(v) && added < 2) {
            added++;
            ans.push_back({i, v});
          }
        }
        cout << "YES" << "\n";
        cout << ans.size() << "\n";
        for (auto [u, v] : ans) {
          cout << u + 1 <<  " " << v + 1 << "\n";
        }
        return;
      }
    }
  }
  cout << "NO" << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
