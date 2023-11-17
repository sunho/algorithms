#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<int> fdp(n, -1);
  fdp[n-1] = 0;
  for (int i=n-2;i>=0;i--){
    if (i+A[i]<n && fdp[i+A[i]] != -1) {
      fdp[i] = fdp[i+A[i]]+1;
    }
  }
  vector<int> bdp(n,-1);
  for (int i=0;i<n-1;i++){
    bdp[i] = fdp[i];
    if (i - A[i] >= 0 && bdp[i-A[i]] != -1) {
      bdp[i] = max(bdp[i], bdp[i-A[i]] + 1);
    }
  }
  vector<int> dp(n,-1);
  for (int i=n-2;i>=0;i--){
    dp[i] = max(bdp[i], fdp[i]);
    if (i+A[i] < n && dp[i+A[i]] != -1) {
      dp[i] = max(dp[i], dp[i+A[i]]+1);
    }
  }
  cout << dp[0] << "\n";
}
