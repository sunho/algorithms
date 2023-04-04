#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  int inf = 1e9;
  vector<int> dp(n+1, inf);
  dp[n] = 0;
  for (int i=n;i>=0;i--){
    string s = to_string(i);
    for (char c : s) {
      int d = c-'0';
      if (i-d >= 0) {
        dp[i-d] = min(dp[i-d], dp[i]+1);
      }
    }
  }
  cout << dp[0] << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
