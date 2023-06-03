#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, t;
  cin >> n >> t;
  int N = 1 << n;
  vector<int> R(n), S(n);
  vector<ld> p(n);
  for (int i=0;i<n;i++){
    cin >> R[i] >> S[i] >> p[i];
  }
  const int MAXN = 1<<17;
  vector dp(t+1, array<ld, MAXN>{});
  dp[0][0] = 1.0l;
  vector sum(t+1, array<ld, MAXN>{});
  vector imos(t+1, array<ld,17>{});
  for (int i=1;i<=t;i++){
    for (int j=0;j<n;j++){
      for (int mask=1;mask<N;mask++){
        int cnt = __builtin_popcount(mask);
        ld uni = 1.0l/(n-cnt+1);
        if (!(mask & (1<<j))) continue;
        for (int win : {0, 1}) {
          int prev_time = win ? i - R[j] - S[j] : i - R[j];
          ld prob = win ? p[j] : 1.0l - p[j];
          int prev_mask = mask^(1<<j);
          if (prev_time >= 0) {
            ld x = sum[prev_time][prev_mask];
            ld y = 0.0l;
            if (x == 0.0l) {
              y = prob*uni*dp[prev_time][prev_mask];
            } else {  
              y = prob*imos[prev_time][j]/x*dp[prev_time][prev_mask];
            }
            dp[i][mask] += y;
            if (win) {
              imos[i][j] += y;
            }
          }
        }
      }
    }
    for (int j=0;j<n;j++){
      imos[i][j] += imos[i-1][j];
    }
    for (int mask=0;mask<N;mask++) {
      for (int j=0;j<n;j++){
        if (mask & (1<<j)) continue;
        sum[i][mask] += imos[i][j];
      }
    }
  }
  for (int i=0;i<n;i++){
    cout << fixed << setprecision(9) << imos[t][i] << "\n";
  }
  cout << gcd(36,302) << "\n";
}
