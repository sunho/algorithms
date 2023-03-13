#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector g(n, vector<int>());
  for (int i=0;i<n-1;i++) {
    int p;
    cin >> p;
    --p;
    g[p].push_back(i+1);
  }
  vector dp(n, 0);
  auto dfs = [&](int u, auto&& self) -> void {
    int res = 0;
    for (auto v : g[u]) {
      self(v, self);
      res += dp[v]+1;
    }
    dp[u] = res;
  };
  dfs(0, dfs);
  for (int i=0;i<n;i++) {
    cout << dp[i] << " ";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
