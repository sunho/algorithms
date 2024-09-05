#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifndef ONLINE_JUDGE
#include "lib/debug.h"
#define dbg(...) std::cerr << __DEBUG_UTIL__::outer << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif


void solve() {
  int n,k;
  cin >> n >> k;
  vector<vector<int>> adj(n);
  vector<int> deg2(n);
  for (int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    --u, --v;
    deg2[u]++;
    deg2[v]++;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  auto check = [&](int x) {
    auto deg = deg2;
    vector<int> comp(n, 1);
    queue<int> q;
    for (int i=0;i<n;i++){
      if (deg[i] == 1) {
        q.push(i);
      }
    }
    int cnt = 0;
    int last = 0;
    while (!q.empty()) {
      int u = q.front();
      last = u;
      q.pop();
      if (comp[u] >= x) {
        comp[u] = 0;
        cnt++;
      }
      for (int v : adj[u]) {
        deg[v]--;
        if (deg[v] == 1) {
          q.push(v);
        }
        comp[v]+=comp[u];
      }
    }
    return cnt > k;
  };
  int ok = 0, ng = n+1;
  while (ng-ok > 1) {
    int mid = (ok+ng)/2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
