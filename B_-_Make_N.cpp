#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  ll n,a,b,x,y,z;
  cin >> n >> a >> b >> x >> y >> z;
  ll ans = min({n/a*y+(n%a)*x, n/b*z+(n%b)*x, n*x});
  if (z*a > b*y) {
    swap(a,b);
    swap(y,z);
  }
  for(ll t=0;t*a<=a*b;t++){
    if (t*a > n) break;
    ll cand = 0;
    cand += t*y;
    cand += (n-t*a)/b*z;
    cand += ((n-t*a)%b)*x;
    ans = min(ans, cand);
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t; 
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
