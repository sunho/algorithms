#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
  string s,t;
  cin >> s >> t;
  int n = max(s.size(), t.size());
  vector<int> A(n), B(n);
  for (int i=0;i<n;i++){
    A[n-i-1] = i < s.size() ? (s[s.size()-i-1] - '0') : 0;
    B[n-i-1] = i < t.size() ? (t[t.size()-i-1] - '0') : 0;
  }
  array<array<ll, 10>, 8> dp{};
  for (int i=0;i<10;i++){
    int state = 0;
    if (i == A[0]) {
      state |= 1;
    }
    if (i == B[0]) {
      state |= 2;
    }
    if (i == 0) {
      state |= 4;
    }
    if (i >= A[0] && i <= B[0])
      dp[state][i] = 1;
  }
  for (int k=1;k<n;k++){
    array<array<ll, 10>, 8> next{};
    for (int t=0;t<8;t++){
      for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
          if (!((t & 4) && i == 0 && j == 0) && i == j) continue;
          if ((t & 1) && j < A[k]) {
            continue;
          }
          if ((t & 2) && j > B[k]) {
            continue;
          }
          int state = 0;
          if ((t&1) && j == A[k]) {
            state |= 1;
          }
          if ((t&2) && j == B[k]) {
            state |= 2;
          }
          if ((t&4) && j == 0) {
            state |= 4;
          }
          next[state][j] += dp[t][i];
        }
      }
    }
    dp = move(next);
  }
  ll ans = 0;
  for (int t=0;t<8;t++){
    for (int i=0;i<10;i++){
      ans += dp[t][i];
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
