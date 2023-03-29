#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,k;
  cin >> n >> k;
  vector g(n, vector<int>(n, false));
  for (int i=0;i<n;i++){
    g[i][i] = true;
  }
  vector<vector<int>> ans;
  for (int i=0;i<k;i++){
    ans.push_back(vector<int>(n));
    vector<int> vis(n);
    int cnt = 0;
    for (int j=0;j<n;j++){
      if (vis[j]) continue;
      int u = j;
      for (int z=j;z<n;z++) {
        int v = z;
        if (!vis[v] && !g[u][v]) {
          vis[u] = true;
          vis[v] = true;
          g[u][v] = true;
          g[v][u] = true;
          ans.back()[v] = u;
          ans.back()[u] = v;
          cnt += 2;
          break;
        }
      }
    }
    if (cnt != n) {
      cout << "Impossible" << "\n";
      return;
    }
  }
  for (int i=0;i<k;i++) {
    for (int j=0;j<n;j++) {
      if (j != n-1) {
        cout << ans[i][j] + 1 << " ";
      } else {
        cout << ans[i][j] + 1;
      }
    }
    cout << "\n";
  }
  
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
