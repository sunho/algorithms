#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  vector<ll> pf(n+1);
  for (int i=0;i<n;i++){
    pf[i+1] = pf[i] + A[i];
  }
  ll ans = 0;
  for (int l=0;l<=k;l++){
    int r = n-(k-l);
    ans = max(ans, pf[r] - pf[2*l]);
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
