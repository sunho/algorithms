#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k, T;
  cin >> n >> k >> T;
  vector<vector<ll>> combs(51, vector<ll>(51));
  combs[0][0] = 1;
  for (int i=1;i<=50;i++){
    combs[i][0] = 1;
    for (int j=1;j<=i;j++){
      combs[i][j] = combs[i-1][j] + combs[i-1][j-1];
    }
  }
  vector<double> P(n);
  vector<int> time(n);
  for (int i=0;i<n;i++){
    cin >> P[i] >> time[i];
  }
  vector<int> id(n);
  iota(begin(id),end(id),0);
  sort(begin(id), end(id), [&](int i, int j){
    return time[i] < time[j];
  });
  vector<double> tmp = P;
  for (int i=0;i<n;i++) P[i] = tmp[id[i]];
  sort(begin(time), end(time));

  vector dp(T+1, vector(k+1, 0.0));
  dp[0][0] = 1;
  vector<double> ans(n);
  for (int i=0;i<n;i++){
    vector next(T+1, vector(k+1, 0.0));
    ll sum = 0;
    for (int t=T;t>=0;t--){
      for (int y=k;y>=0;y--) {
        int need = k-y-1, avail = n-i;
        if (avail >= 1) {
          double prob = max((double)(k-y-1)/(n-i),0.0);
          next[t][y] += dp[t][y] * (1.0-prob);
          if (y >= 1) {
            // cout << dp[t][y-1] << "\n";
            if (t-time[i] >= 0) {
              // if (avail >= need)
              ans[id[i]] += dp[t-time[i]][y-1] * P[i];
              next[t][y] += dp[t-time[i]][y-1] * P[i] * prob;
            }
            next[t][y] += dp[t][y-1] * (1.0-P[i]) * prob;
          }
        }
      }
    }
    dp = move(next);
  }
  for (auto p : ans) {
    cout << setprecision(10) << fixed << p << "\n";
  }
}


/*

(0,0) 1.0
(1,0) 

1 2 3
2/3
1/2

*/