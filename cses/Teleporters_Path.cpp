#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<int> indeg(n), outdeg(n);
  vector adj(n, vector<int>());

  while (m--){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    indeg[v]++, outdeg[u]++;
  }

  for (int i=1;i<n-1;i++) {
    if (indeg[i] != outdeg[i]) {
      cout << "IMPOSSIBLE" << "\n";
      return 0;
    }
  }
  if (indeg[0]+1 != outdeg[0]  || indeg[n-1] != outdeg[n-1]+1) {
    cout << "IMPOSSIBLE" << "\n";
    return 0;
  }

  adj[n-1].push_back(0);
    
  vector<int> ans;
  auto tour = [&](auto self, int u) -> void {
    while (!adj[u].empty()) {
      int v = adj[u].back();
      adj[u].pop_back();
      self(self, v);
    }
    ans.push_back(u);
  };
  tour(tour, n-1);
  ans.pop_back();
  reverse(begin(ans), end(ans));
  for (int i=0;i<n;i++){
    if (adj[i].size()) {
      cout << "IMPOSSIBLE" << "\n";
      return 0;
    }
  }

  for (int v : ans) {
    cout << v + 1 << " ";
  }
}
