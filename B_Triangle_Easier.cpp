#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>(n));
  while (m--){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u][v] = 1;
    adj[v][u] = 1;
  }
  int ans = 0;
  for (int i=0;i<n;i++){
    for (int j=i+1;j<n;j++){
      for (int k=j+1;k<n;k++){
        if (adj[i][j] && adj[j][k] && adj[k][i]) {
          ans++;
        }
      }
    }
  }
  cout << ans << "\n";
}
