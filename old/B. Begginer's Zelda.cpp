#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> deg(n);
  for (int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    deg[u] ++;
    deg[v] ++;
  }
  int sum = 0;
  for (int i=0;i<n;i++){
    if (deg[i] == 1) {
      sum++;
    }
  }
  cout << (sum+1)/2  << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
