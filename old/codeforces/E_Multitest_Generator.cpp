#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i=0;i<n;i++)
    cin >> A[i];
  vector<array<int,2>> dp(n+1, {-1,-1});
  dp[n][0] = 0;
  int maxi = 0;
  for (int i=n-1;i>=0;i--){
    if (i+A[i]+1 <= n) {
      if (dp[i+A[i]+1][0] != -1)
        dp[i][0] = max(dp[i][0], dp[i+A[i]+1][0] + 1);
      if (dp[i+A[i]+1][1] != -1)
        dp[i][1] = max(dp[i][0], dp[i+A[i]+1][1] + 1);
    }
    dp[i][1] = max(dp[i][1], maxi+1);
    maxi = max(maxi, dp[i][0]);
  } 
  vector<int> ans(n-1);
  set<int> avail;
  for (int i=n-2;i>=0;i--){
    if (dp[i+1][0] == A[i]) {
      ans[i] = 0;
    } else if (dp[i+1][0] != -1) {
      ans[i] = 1;
    } else if (dp[i+1][1] >= A[i]) {
      ans[i] = 1;
    } else {
      ans[i] = 2;
    }
  }
  for (int i=0;i<n-1;i++){
    cout << ans[i] << " ";
  }
  cout << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
