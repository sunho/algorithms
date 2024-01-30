#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll n,k;
  cin >> n >> k;
  if (n%2 == 1) {
    cout << -1 << "\n";
    return;
  }
  vector<vector<ll>> dp(n+1, vector<ll>(n+1, -1));
  auto dfs = [&](auto&& self, int i, int lvl) -> ll {
    auto& sdp = dp[i][lvl];
    if (sdp != -1) {
      return sdp;
    }
    if (i == n) {
      if (lvl == 0) {
        return 1;
      } else {
        return 0;
      }
    }
    sdp = 0;
    if (lvl != 0) {
      sdp += self(self, i+1, lvl-1);
    }
    if (lvl != n) {
      sdp += self(self, i+1, lvl+1);
    }
    return sdp;
  };
  string ans(n, ' ');
  int lvl = 0;
  for (int i=0;i<n;i++){
    if (dfs(dfs, i+1, lvl+1) > k) {
      ans[i] = '(';
      lvl++;
    } else if (lvl != 0) {
      k -= dfs(dfs, i+1, lvl+1);
      lvl--;
      ans[i] = ')';
    } else {
      cout << -1 << "\n";
      return;
    }
  }
  cout << ans;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
