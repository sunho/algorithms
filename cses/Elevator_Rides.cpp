#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, x;
  cin >> n >> x;
  int N = 1<<n;
  int inf = 1e9;
  vector dp(N+1, pair<int,int>{inf,inf});
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  dp[0] = {1,0};
  for (int mask=0;mask<N;mask++){
    for (int i=0;i<n;i++){
      if (mask & (1<<i)) {
        auto best = dp[mask ^ (1<<i)];
        if (best.second + A[i] <= x) {
          best.second += A[i];
        } else {
          best.first++;
          best.second = A[i];
        }
        dp[mask] = min(dp[mask], best);
      }
    }
  }
  cout << dp[N-1].first << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
