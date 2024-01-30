#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,k,x;
  cin >> n >> k >> x;
  vector<int> A(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  sort(begin(A),end(A));
  vector<ll> pf(n+1);
  for (int i=0;i<n;i++){
    pf[i+1] = pf[i] + A[i];
  }
  const ll inf = 1e18;
  ll ans = -inf;
  for (int i=0;i<=k;i++){
    ll cand = pf[n] - (pf[n] - pf[max(n-i,0)]) - 2*(pf[max(n-i,0)]-pf[max(n-i-x,0)]);
    ans = max(ans,cand);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
