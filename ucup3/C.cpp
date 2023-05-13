#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll pow10(int n) {
  ll res = 1;
  while (n--) res *= 10;
  return res;
}

void solve() {
  ll x; int k;
  cin >> x >> k;
  string s = to_string(x);
  reverse(begin(s), end(s));
  int n = s.size();
  const ll inf = 2e18+2;
  vector<array<array<ll, 2>,19>> dp(n+1);
  for (auto& arr : dp) for (auto& arr2 : arr) fill(begin(arr2),end(arr2),inf);
  if (k == 0) {
    for (int i=0;i<n;i++){
      int d = s[i] - '0';
      if (d != 9) {
        cout << 1;
        for (int z=0;z<i;z++){
          cout << 0;
        }
        cout << "\n";
        return;
      }
    }
    cout << 1;
    for (int z=0;z<n;z++){
      cout << 0;
    }
    cout << "\n";
    return;
  }
  dp[0][0][0] = 0;
  for (int i=0;i<n;i++){
    int d = s[i] - '0';
    int nines = 0;
    for (int j=i;j<n;j++){
      int d2 = s[j] - '0';
      if (d2 == 9) {
        nines++;
      } else {
        break;
      }
    }
    ll ten = pow10(i);
    for (int k=0;k<=18;k++){
      if (nines > 0) {
        if (k + nines <= 18) {
          auto& res = dp[i+nines][k+nines][1];
          res = min(res, dp[i][k][0] + ten);
          res = min(res, dp[i][k][1]);
          dp[i+nines][k+nines][0] = min(res, dp[i+nines][k+nines][0]);
        }
      } else {
        if (k + 1 <= 18) {
          auto& res = dp[i+1][k+1][1];
          if (d != 0)
            res = min(res, dp[i][k][0] + (10-d)*ten);
          res = min(res, dp[i][k][1] + (10-d-1)*ten);
          if (i + 1 == n || s[i+1] != '9') {
            dp[i+1][k+1][0] = min(res, dp[i+1][k+1][0]);
          }
        }
      }
      dp[i+1][k][0] = min(dp[i+1][k][0], dp[i][k][0]);
    }
  }
  if (dp[n][k][0] != inf) {
    cout << dp[n][k][0] << "\n";
    return;
  }
  for (int i=k;i>=0;i--){
    if (dp[n][i][1] != inf) {
      string t = to_string(dp[n][i][1]);
      for (int z=0;z<k-i;z++){
        cout << 9;
      }
      for (int z=(int)t.size();z<n;z++){
        cout << 10-(s[z]-'0')-1;
      }
      cout << dp[n][i][1];
      cout << "\n";
      return;
    }
  }
  cout << -1 << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
