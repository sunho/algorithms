#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> dp(n + 1, vector<int>(3, 0));
  dp[0][0] = 0;
  dp[0][1] = 0;
  dp[0][2] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      if (j == 0 || j == 1) {
        for (int z = max(0, i - k / 2); z < i; z++) {
          if (z == 0) {
            dp[i][j] = 1;
          } else {
            if (j == 0) {
              dp[i][j] |= dp[z][1];
            } else {
              dp[i][j] |= !dp[z][2];
            }
          }
        }
      } else {
        for (int z = max(0, i - k); z < i; z++) {
          if (z == 0) {
            dp[i][j] |= 1;
          } else {
            dp[i][j] |= !dp[z][0];
          }
        }
      }
    }
  }
  if (dp[n][0]) {
    cout << "A and B win"
         << "\n";
  } else {
    cout << "C win"
         << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
