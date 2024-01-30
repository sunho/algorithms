#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  const int MOD = 1e9;
  int n, k;
  cin >> n >> k;
  vector<int> dp(n+1);
  dp[0] = 1;
  for (int i=0;i<k;i++){
    vector<int> nxt(n+1);
    for (int j=0;j<=n;j++){
      for (int x=0;x<=n;x++){
        if (j+x <= n) {
          nxt[j+x] += dp[j];
          nxt[j+x] %= MOD;
        }
      }
    }
    dp = nxt;
  }
  cout << dp[n];
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
