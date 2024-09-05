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
  vector<int> cnt(30);
  for (int i=0;i<n;i++){
    for (int j=0;j<30;j++){
      if (A[i] >> j & 1) {
        cnt[j]++;
      }
    }
  }
  const int MOD = 1e9 + 7;
  ll ans = 1;
  for (int i=0;i<n;i++){
    int x = 0;
    for (int j=0;j<30;j++){
      if (cnt[j] > 0) {
        x |= (1<<j);
        cnt[j]--;
      }
    }
    ans *= x;
    ans %= MOD;
  }
  cout << ans;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
