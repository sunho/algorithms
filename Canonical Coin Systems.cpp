#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  sort(begin(A),end(A));
  const int m = *max_element(begin(A),end(A));
  int mm = 2*m;
  const int inf = 1e9;
  vector<int> dp(mm+1, inf);
  dp[0] = 0;
  for (int i=0;i<n;i++){
    for (int j=1;j<=mm;j++){
      if (j-A[i] >= 0){
        dp[j] = min(dp[j-A[i]]+1,dp[j]);
      }
    }
  }
  for (int j=1;j<=mm;j++){
    int res = 0;
    int rem = j;
    while (rem) {
      int c = *--upper_bound(begin(A),end(A),rem);
      res += rem/c;
      rem %= c;
    }
    if (res > dp[j]) {
      cout << "non-canonical" << "\n";
      return;
    }
  }
  cout << "canonical" << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
