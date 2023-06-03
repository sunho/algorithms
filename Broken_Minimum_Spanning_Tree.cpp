#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge {
  int u,v,w;
  bool operator<(const edge& other) const {
    return tie(w,u,v) < tie(other.w, other.u, other.v);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  vector<edge> edges(m);
  map<edge, int> edge_to_id;
  for (int i=0;i<m;i++){
    edge e;
    cin >> e.u >> e.v >> e.w;
    // if (e.u > e.v) swap(e.u, e.v);
    --e.u, --e.v;
    edges[i] = e;
    if (!edge_to_id.count(e))
      edge_to_id[e] = i;
  }
  vector<bool> used(m);
  for (int i=0;i<n-1;i++) {
    used[i] = true;
  }
  vector<pair<int,int>> ans;
  for (auto [e, eid] : edge_to_id){
    if (!used[eid]) {
      vector<int> color(n);
      vector<int> prd(n);
      vector<int> prd_edge(n);
      vector<vector<pair<int,int>>> adj(n);
      for (int i=0;i<m;i++){
        if (used[i]) {
          adj[edges[i].u].push_back({edges[i].v, i});
          adj[edges[i].v].push_back({edges[i].u, i});
        }
      }
      adj[e.u].push_back({e.v, eid});
      adj[e.v].push_back({e.u, eid});
      int mx = -1;
      int mx_i = -1; 
      auto dfs = [&](auto self, int u, int p) -> bool {
        color[u] = 2;
        for (auto [v, eid] : adj[u]) {
          if (p == eid) continue;
          if (color[v] == 2) {
            int cur = u;
            mx = edges[eid].w;
            mx_i = eid;
            while (cur != v) {
              auto cur_e_id = prd_edge[cur];
              auto cur_e = edges[cur_e_id];
              if (mx < cur_e.w) {
                mx = cur_e.w;
                mx_i = cur_e_id;
              }
              cur = prd[cur];
            }
            return true;
          } else if (color[v] == 0) {
            prd[v] = u;
            prd_edge[v] = eid;
            if (self(self, v, eid)) return true;
          }
        }
        color[u] = 1;
        return false;
      };
      dfs(dfs, e.u, -1);
      if (mx != -1 && mx > edges[eid].w) {
        ans.push_back({mx_i, eid});
        used[eid] = true;
        used[mx_i] = false;
      } 
    }
  }
  cout << ans.size() << "\n";
  for (auto [u,v] : ans) {
    cout << u + 1 << " " << v + 1 << "\n";
  }
}