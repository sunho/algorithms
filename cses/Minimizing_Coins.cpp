#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,x;
  cin >> n >> x;
  int inf = 1e9;
  vector dp(x+1, inf);
  vector p(x+1, 0);
  dp[0] = 0;
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    for (int j=0;j<x;j++){
      if (j + a <= x) {
        if (dp[j+a] > dp[j] + 1) {
          dp[j+a] = dp[j] + 1;
        }
      }
    }
  }
  if (dp[x] == inf) {
    cout << -1 << "\n";
    return;
  }
  cout << dp[x] << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
