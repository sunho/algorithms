#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  vector<ll> A(n);
  ll sum = 0;
  for (int i=0;i<n;i++){
    cin >> A[i];
    sum += A[i];
  }
  sort(A.begin(), A.end());
  const ll inf = 1e18;
  vector<ll> pf(n+1, inf);
  for (int i=0;i<n;i++){
    pf[i+1] = min(pf[i], A[i] - i);
  }
  auto check = [&](ll a, int k) {
    if (k <= n) {
      ll mn = pf[k] + k;
      if (k != n) {
        mn = min(mn, A[k]);
      }
      if (mn < a) return false;
    } else {
      int m = n;
      if (k%2 != m%2) {
        m--;
      }
      ll mn = pf[m] + k;
      if (m != n)
        mn = min(mn, A[m]);
      if (mn < a) return false;
      ll rem = (k - m)/2;
      ll x = sum;
      x += (ll)k*(k+1)/2 - (ll)(k-m)*(k-m+1)/2;
      if (x - a*n < rem) {
        return false;
      }
    }
    return true;
  };
  while (q--) {
    int k;
    cin >> k;
    if (n == 1) {
      cout << A[0] + (k+1)/2 * (k&1?1:-1) << "\n";
      continue;
    }
    ll ok = -1e10, ng = 1e10;
    while (ng-ok > 1) {
      ll mid = (ok+ng)/2;
      if (check(mid, k)) ok = mid;
      else ng = mid;
    }
    cout << ok << " ";
  } 
}
