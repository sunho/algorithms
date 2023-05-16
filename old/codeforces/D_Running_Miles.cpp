#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  const int inf = 1e9;
  array<int,4> dp{0,-inf,-inf,-inf};
  for (int i=0;i<n;i++){
    array<int,4> next = dp;
    for (int j=0;j<3;j++){
      if (j == 2) {
        next[j+1] = max(next[j+1], dp[j] + A[i] - i);
      } else if (j == 0) {
        next[j+1] = max(next[j+1], dp[j] + A[i] + i);
      } else {
        next[j+1] = max(next[j+1], dp[j] + A[i]);
      }
    }
    dp = next;
  }
  cout << dp[3] << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
