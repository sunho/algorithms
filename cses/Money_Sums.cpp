#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  const int N = 1e5;
  vector dp(N+1, false);
  dp[0] = true;
  int n;
  cin >> n;
  int ans_size = 0;
  for(int i=0;i<n;i++) {
    int c;
    cin >> c;
    for (int j=N;j>=0;j--){
      if (j-c >= 0) {
        if (!dp[j] && dp[j-c]) {
          dp[j] = true;
          ans_size++;
        }
      }
    }
  }
  cout << ans_size << "\n";
  for (int i=1;i<=N;i++){
    if (dp[i])
      cout << i << " ";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
