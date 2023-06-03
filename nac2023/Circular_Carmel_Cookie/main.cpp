#include <bits/stdc++.h>
#include <cfloat>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  auto check = [&](ll r2) {
    ll cnt = 0;
    for (ll i=1;i*i<=r2;i++){
      cnt += 4*(ll)sqrtl(r2-i*i);
      if (cnt > n) {
        return true;
      }
    }
    return cnt > n;
  };
  ll ok = (ll)1e9 + 1, ng = 1;
  while (ok - ng > 1) {
    ll mid = (ok+ng)/2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  cout << setprecision(10) << fixed << sqrt(ok) << "\n";
}
