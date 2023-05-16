#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,m;
  cin >> n >> m;
  const int inf = 1e9;
  vector<bool> dp(m+1);
  dp[0] = true;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  sort(A.begin(),A.end());
  vector<ll> pf(n+1);
  for (int i=0;i<n;i++){
    pf[i+1] = pf[i] + A[i];
  }
  int ans = 0;
  for (int i=n-1;i>=0;i--){
    int mn = A[i];
    ll sum = pf[i];
    for (int rem=1;rem<mn;rem++){
      if (m-rem-sum >= 0 && dp[m-rem-sum]) {
        ans = max(ans, rem);
      }
    }
    for (int j=m;j>=0;j--){
      if (j-mn >= 0) {
        dp[j] = dp[j] | dp[j-mn];
      }
    }
  }
  cout << min((ll)m,pf[n])-ans << "\n";
}
