#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  ll x,a,d,n;
  cin >> x >> a >> d >> n;
  ll amin = min(a, a + d*(n-1));
  ll amax = max(a, a + d*(n-1));
  if (x < amin) {
    cout << amin-x << "\n";
  } else if (x > amax) {
    cout << x-amax << "\n";
  } else if (d != 0) {
    ll a1 = a + (x-a)/d*d;
    ll a2 = a + ((x-a)/d+1)*d;
    cout << min(abs(a1-x), abs(a2-x)) << "\n";
  } else {
    cout << abs(x-a) << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
