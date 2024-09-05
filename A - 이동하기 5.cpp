#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector<int> A(n), B(m);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  for (int i=0;i<m;i++){
    cin >> B[i];
  }
  int mx = *max_element(begin(A),end(A));
  int mx2 = *max_element(begin(B),end(B));
  ll ans = (ll)(m-1)*mx*(int)(1e9);
  int tgt1 = -1, tgt2 = 0;
  for (int i=0;i<n;i++){
    if (A[i] == mx) {
      if (tgt1 == -1) {
        tgt1 = i;
      }
      tgt2 = i;
    }
  }
  ans += B.back()*(n-tgt2-1) + mx2 * (tgt2-tgt1) + B[0]*tgt1;
  for (int i=0;i<n;i++){
    ans += (ll)1e9*A[i];
  }
  for (int i=0;i<m;i++) {
    ans += B[i];
  }
  cout << ans;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
