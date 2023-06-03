#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,k,m;
  cin >> n >> k >> m;
  vector<vector<vector<int>>> adj(k, vector(n, vector<int>()));
  vector<int> last(n);
  for (int i=0;i<m;i++){
    int u,v,d;
    cin >> u >> v >> d;
    --u,--v,--d;
    adj[d][u].push_back(v);
    adj[d][v].push_back(u);
    last[u] = max(last[u], d);
    last[v] = max(last[v], d);
  }

  set<int> ans;

  for (int s=0;s<n;s++){
    if (last[s] >= 1) {
      continue;
    }
    set<int> pos;
    pos.insert(s);
    for (int d=0;d<k;d++){
      set<int> next;
      for (int u : pos) {
        for (int v : adj[d][u]) {
          if (d+1>=last[v])
            next.insert(v);
        }
      }
      pos = move(next);
    }
    for (int v : pos) {
      ans.insert(v);
    }

  }
  cout << ans.size() << "\n";
  for (int v : ans) {
    cout << v + 1 << "\n";
  }
}
