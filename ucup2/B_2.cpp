#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  string s;
  cin >> s;

  int n = s.size();
  if (n < 4) {
    cout << 0 << "\n";
    return 0;
  }

  const int inf = 1e9;
  vector<array<int,8>> dp(n-3+1);
  for (int i=0;i<=n-3;i++){
    fill(begin(dp[i]), end(dp[i]), -inf);
  }
  int cur = 0;
  for (int i=0;i<3;i++){
    cur |= (s[i]-'0') << (2-i);
  }
  dp[0][cur] = 0;
  for (int i=0;i<n-3;i++){
    for (int mask = 0; mask < 8; mask++) {
      if (dp[i][mask] == -inf) continue;
      int new_mask = ((mask << 1) & 7) | (s[i+3]-'0');
      if (new_mask == 0b0101) {
        dp[i+1][0b010] = max(dp[i+1][0b010], dp[i][mask] + 1);
      }
      dp[i+1][new_mask & 7] = max(dp[i+1][new_mask & 7], dp[i][mask]);
    }
  }
  int ans = 0;
  for (int i=0;i<8;i++) {
    ans = max(ans, dp[n-3][i]);
  }
  cout << ans << "\n";
}
