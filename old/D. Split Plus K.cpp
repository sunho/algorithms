#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> A(n);
  set<ll> S;
  set<ll> cands;
  for (int i=0;i<n;i++){
    cin >> A[i];
    S.insert(A[i]);
  }
  sort(begin(A),end(A));
  if (S.size() == 1) {
    cout << 0 << "\n";
    return;
  }
  ll d = 0;
  for (int i=0;i<n;i++){
    d = gcd(d, k-A[i]);
  }
  d = abs(d);
  ll ans = 0;
  bool found = false;
  for (ll s : {k - d, k+d}){
    const ll inf = 1e18;
    ll cand = 0;
    bool ok = true;
    for (ll x : A) {
      if ((s-x) % (k-s) != 0) {
        ok = false;
        break;
      }
      ll t = (s-x)/(k-s);
      if (t < 0) {
        ok = false;
        break;
      }
      cand += t;
    }
    if (ok) {
      found = true;
      ans = cand;
    }
  }
  if (found)  {
    cout << ans << "\n";
  } else {
    cout << -1 << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
