#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
  }
  vector<int> deg(n);
  vector<int> ans(n);
  for (int i=0;i<n;i++){
    ans[i] = (i + 1 - deg[i]) + adj[i].size();
    for (int v : adj[i]) {
      deg[v] ++;
    }
  }
  vector<int> B(n);
  iota(begin(B),end(B),1);
  auto ans2 = ans;
  sort(begin(ans2),end(ans2));
  if (ans2 != B) {
    cout << -1;
    return;
  }
  for (int d : ans) {
    cout << d << " ";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
