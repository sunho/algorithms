#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ilog2(int x) {
  return x == 0 ? 0 : 31 - __builtin_clz(x);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> A(n+1);
  for (int i=1;i<=n;i++){
    cin >> A[i];
  }
  vector<pair<int,int>> W;
  auto dfs = [&](auto self, int u) -> void {
    if (u > n) return;
    self(self, 2*u);
    W.push_back({A[u], ilog2(u)});
    self(self, 2*u+1);
  };
  dfs(dfs, 1);
  int k = ilog2(n);
  const ll inf = 1e18;
  ll ans = -inf;
  for (int l=0;l<=k;l++){
    for (int r=l;r<=k;r++){
      ll cur = 0;
      for (int i=0;i<n;i++){
        auto [a,d] = W[i];
        if (l <= d && d <= r) {
          cur += a;
          ans = max(ans, cur);
          if (cur < 0) { 
            cur = 0;
          }
        }
      }
    }
  }
  cout << ans << "\n";
}
