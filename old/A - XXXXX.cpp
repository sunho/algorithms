#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> A(n);
  vector<ll> pf(n+1);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  for (int i=0;i<n;i++){
    pf[i+1] = (pf[i] + A[i]) % x;
  }
  const int inf = n+1;
  vector<int> mx(x, -inf), mn(x, inf);
  for (int i=0;i<=n;i++){
    mx[pf[i]] = max(mx[pf[i]], i);
    mn[pf[i]] = min(mn[pf[i]], i);
  }
  int ans = -1;
  for (int i=0;i<x;i++){
    for (int j=0;j<x;j++){
      if (i == j) continue;
      ans = max(ans, mx[j]-mn[i]);
    }
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
