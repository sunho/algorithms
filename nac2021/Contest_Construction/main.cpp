#include <bits/stdc++.h>
using namespace std;
using lll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,k;
  cin >> n >> k;

  map<int,int> cnt;
  for (int i=0;i<n;i++) {
    int a;
    cin >> a;
    cnt[a]++;
  }

  vector binom(n+1, vector(k+1, 0ll));
  binom[0][0] = 1;
  for (int i=1;i<=n;i++){
    binom[i][0] = 1;
    for (int j=1;j<=min(i,k);j++){
      binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
    }
  }

  vector<lll> vals = {0};
  for (auto [a, _] : cnt) vals.push_back(a);
  int m = vals.size();
  vector dp(m, vector(m, vector<lll>(k+1, 0)));
  dp[0][0][0] = 1;
  for (auto [a, c] : cnt) {
    auto next = dp;
    int a_i = lower_bound(vals.begin(), vals.end(), a) - vals.begin();
    for (int x=0;x<c;x++) {
      for (int i=0;i<m;i++){
        for (int j=i;j<m;j++){
          if (vals[i] != 0 && vals[j] != 0 && vals[i] + vals[j] < a) continue;
          int nxt[2];
          if (x == 0) {
            nxt[0] = j; nxt[1] = a_i;
          } else {
            nxt[0] = a_i; nxt[1] = a_i;
          }
          for (int z=0;z<k;z++) {
            if (z+x+1 <= k) next[nxt[0]][nxt[1]][z+x+1] += dp[i][j][z] * binom[c][x+1];
          }
        }
      }
    }
    dp = move(next);
  }
  lll ans = 0;
  for (int i=0;i<m;i++){
    for (int j=i;j<m;j++){
      ans += dp[i][j][k];
    }
  }
  cout << ans << "\n";
}
