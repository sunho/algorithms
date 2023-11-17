#include <bits/stdc++.h>

using namespace std;

void solve() {
  vector<int> n(2);
  vector<vector<int>> X(2), Y(2);
  vector<vector<int>> id(2);
  for (int k : {0,1}) {
    cin >> n[k];
    X[k] = vector<int>(n[k]);
    Y[k] = vector<int>(n[k]);
    for (int i=0;i<n[k];i++){
      cin >> X[k][i];
    }
    for (int i=0;i<n[k];i++){
      cin >> Y[k][i];
    }
    id[k] = vector<int>(n[k]);
    iota(begin(id[k]),end(id[k]),0);
    sort(begin(id[k]),end(id[k]),[&](int i, int j) {
      return Y[k][i] < Y[k][j];
    });
  }
  vector<vector<int>> adj(n[0]+n[1], vector<int>());
  for (int k : {0, 1}) {
    int sz1 = X[k].size();
    int sz2 = X[1-k].size();
    priority_queue<tuple<int,int,int>> pq;
    for (int i=0;i<sz2;i++){
      pq.push({X[1-k][i], Y[1-k][i], i});
    }
    int cur = 0;
    pair<int,int> mx = {-1,-1};
    for (int i=sz1-1;i>=0;i--){
      int x = X[k][id[k][i]], y = Y[k][id[k][i]];
      while (!pq.empty() && get<0>(pq.top()) > y) {
        auto [x2,y2,j] = pq.top();
        mx = max(mx, {y2, j});
        pq.pop();
      }
      if (mx.first != -1) {
        int u = id[k][i]+(k==1?n[0]:0);
        int v = mx.second+(k==0?n[0]:0);
        adj[u].push_back(v);
      }
    }
  }
  vector<int> vis(n[0]+n[1]);
  vector<int> dp(n[0]+n[1],-1);
  auto dfs = [&](auto& self, int u) {
    if (dp[u]!=-1) {
      return dp[u];
    }
    if (vis[u] == 2) {
      return dp[u] = 2;
    }
    if (adj[u].empty()) {
      return dp[u] = (u >= n[0]);
    }
    vis[u] = 2;
    int v = *adj[u].begin();
    int res = self(self, v);
    vis[u] = 1;
    return dp[u] = res;
  };
  vector<int> ans(3);
  for (int i=0;i<n[0];i++){
    ans[dfs(dfs,i)]++;
  }
  swap(ans[1], ans[2]);
  cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
