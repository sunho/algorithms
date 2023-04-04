#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,q;
  cin >> n >> q;
  int N = 1e9;
  int l = ceil(log2(N));
  vector down(n, array<int, 32>{});
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    --a;
    down[i][0] = a;
  }

  for (int i=1;i<l;i++){
    for (int j=0;j<n;j++){
      down[j][i] = down[down[j][i-1]][i-1];
    }
  }
  while (q--){
    int u,k;
    cin >> u >> k;
    --u;
    int cur = u;
    for (int i=l-1;i>=0;i--){
      if (k & (1<<i)) {
        cur = down[cur][i];
      }
    }
    cout << cur + 1 << "\n";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
