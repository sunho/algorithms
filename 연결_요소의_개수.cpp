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
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    --a,--b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int cnt = 0;
  vector<bool> vis(n);
  auto dfs = [&](int u, auto&& self) {
    if (vis[u]) return;
    vis[u] = true;
    for (int v : g[u]) {
      self(v, self);
    }
  };
  for(int u=0;u<n;u++){
    if (!vis[u]) {
      dfs(u, dfs);
      cnt++;
    }
  }
  cout << cnt << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
