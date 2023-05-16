#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  vector<ll> pf(n+1);
  for (int i=0;i<n;i++){
    pf[i+1] = pf[i] + A[i];
  }
  ll cur = 0;
  for (int i=0;i<m;i++){
    cur += (ll)(i+1) * A[i];
  }
  ll ans = cur;
  for (int i=m;i<n;i++){
    cur += (ll)m*A[i];
    cur -= pf[i] - pf[i-m];
    ans = max(ans, cur);
  }
  cout << ans << "\n";
}
