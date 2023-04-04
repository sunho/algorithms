#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, x;
  cin >> n >> x;
  int inf = 1e9;
  vector dp(x+1, 0);
  vector h(n, 0);
  vector s(n, 0);
  for (int i=0;i<n;i++){
    cin >> h[i];
  }
  for (int i=0;i<n;i++){
    cin >> s[i];
  }
  int sum = 0;
  for (int i=0;i<n;i++){
    sum = min(x, sum+h[i]);
    for (int j=sum;j>=0;j--){
      if (j - h[i] >= 0) {
        dp[j] = max(dp[j-h[i]] + s[i], dp[j]);
      }
     }
  }
  cout << *max_element(begin(dp), end(dp)) << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
