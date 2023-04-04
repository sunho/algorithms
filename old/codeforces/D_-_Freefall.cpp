#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

// A / sqrt(1+t) + t*B
// B + 1/sqrt(1+t)
// 
// 

using lll = __int128;

void solve() {
  ll A, B;
  cin >> A >> B;
  ll l = -1, r = 1e18;
  auto f = [&](ll t) {
    long double calc = A / sqrt(1+t) + (long double)t*B;
    return calc;
  };
  while (r-l > 5){
    ll m1 = (l*2 + r)/3, m2 = (l+r*2)/3;
    if (f(m1) < f(m2)) r = m2;
    else l = m1;
  }
  long double ans = 1e18;
  for (ll t = l; t <= r; ++t) {
    ckmin(ans, f(t));
  }
  cout << fixed << setprecision(10) << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
