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
  const ll inf = 1e18;
  vector<ll> dp(3, -inf);
  dp[0] = 0;
  for (int i=0;i<n;i++){
    vector<ll> next(3, -inf);
    for (int j=1;j<=2;j++){
      next[j-1] = max(next[j-1], dp[j]+2*A[i]);
    }
    next[0] = max(next[0], dp[0] + A[i]);
    next[2] = max(next[2], dp[0] + 2*A[i]);
    dp = next;
  }
  cout << max({dp[0], dp[1], dp[2]});
}
