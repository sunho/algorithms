#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vector<int> K(k);
  for (int i=0;i<k;i++){
    cin >> K[i];
  }

  vector<array<bool, 2>> dp(n+1);
  dp[0][0] = false;
  dp[0][1] = false;
  for (int i=1;i<=n;i++){
    for (int p=0;p<2;p++){
      bool res = false;
      for (int j=0;j<k;j++){
        if (i - K[j] >= 0) {
          res |= !dp[i-K[j]][p^1];
        }
      }
      dp[i][p] = res;
    }
  }
  for (int i=1;i<=n;i++){
    if (dp[i][0]) cout << "W";
    else cout << "L";
  }
}
