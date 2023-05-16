#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  array<array<char,10>,10> M{};
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin >> M[i][j];
    }
  }
  array<int, 10> A{};
  for (int i=0;i<n;i++){
    int mask = 0;
    for (int j=0;j<m;j++){
      if (M[i][j] == 'x')
        mask |= (1<<j);
    }
    A[i] = mask;
  }

  vector<int> dp(1<<m);
  for (int i=n-1;i>=0;i--){
    vector<int> next(1<<m);
    for (int mask=0;mask<(1<<m);mask++){
      for (int mask2=0;mask2<(1<<m);mask2++){
        bool ok = true;
        if (mask2&((mask<<1)|(mask>>1))) ok = false;
        if (A[i]&mask2) ok = false;
        if (mask2&((mask2<<1)|(mask2>>1))) ok = false;
        if (ok) {
          next[mask2] = max(next[mask2], dp[mask] + (int)bitset<32>(mask2).count());
        }
      }
    }
    dp = move(next);
  }
  int ans = 0;
  for (int i=0;i<(1<<m);i++){
    ans = max(ans, dp[i]);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
