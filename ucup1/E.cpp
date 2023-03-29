#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  ll m;
  cin >> m;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  auto f = [&](ll x) {
    vector<ll> B(n, x);
    for (int i=0;i<n;i++){
      B[i] = (B[i]+A[i]-1)/A[i];
    }
    int z = n;
    for (int i=n-1;i>=0;i--){
      if (B[i] != 0) {
        break;
      }
      z = i;
    }
    ll cnt = 0;
    for (int i=0;i<z;i++){
      if (i == z-1 && B[i] <= 0)
        break;
      cnt++;
      B[i]--;
      if (B[i] > 0) {
        cnt += 2*B[i];
        if (cnt > m) 
          return false;
        if (i + 1 < n)
          B[i+1] -= B[i];
      }
    }
    return cnt <= m;
  };

  ll ok = 0, ng = 1e18;
  while (ng-ok > 1) {
    ll mid = (ok+ng)/2;
    if (f(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();

}
