#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,q;
  cin >> n >> q;
  vector<int> prd(n+1);
  prd[0] = n;
  prd[n] = n;
  for (int i=1;i<n;i++){
    cin >> prd[i];
    prd[i]--;
  }
  vector<array<int, 32>> up(n+1);
  int l = ceil(log2(n+1));
  for (int i=0;i<l;i++){
    for (int j=0;j<=n;j++){
      if (i == 0)
        up[j][i] = prd[j];
      else
        up[j][i] = up[up[j][i-1]][i-1];
    }
  }

  auto get_up = [&](int u, int k) -> int {
    for (int i=0;i<l;i++){
      if (k & (1<<i)){
        u = up[u][i];
      }
    }
    return u;
  };

  while(q--){
    int u,k;
    cin >> u >> k;
    --u;
    int v = get_up(u, k);
    if (v == n) {
      cout << -1 << "\n";
    } else {
      cout << v + 1 << "\n";
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
