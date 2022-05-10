#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> indeg(n), outdeg(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    --a,--b;
    g[b].push_back(a);
    indeg[b]++;
    outdeg[a]++;
  }
  vector<int> dp(n, -1);
  auto dfs = [&](int u, auto&& self) {
    if (dp[u] != -1) return dp[u];
    int res = 1;
    if (indeg[u] > 1) {
      for(auto v : g[u]) {
        if (outdeg[v] > 1) {
          ckmax(res, self(v, self) + 1);
        }
      }
    }
    dp[u] = res;
    return dp[u];
  };
  int ans = 0;
  for(int u = 0; u < n; u++){
    ckmax(ans, dfs(u, dfs));
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
