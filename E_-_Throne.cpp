#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll normalize(ll x, ll mod) { x %= mod; if (x < 0) x += mod; return x; }
tuple<ll,ll,ll> exgcd(ll a, ll b) {
  ll x = 1, y = 0;
  ll x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    ll q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return {a1,x,y};
}

void solve() {
  int n,s,k;
  cin >> n >> s >> k;
  s = n-s;
  int g = gcd(k,n);
  if (s % g != 0) {
    cout << -1 << "\n";
    return;
  }
  n /= g;
  k /= g;
  s /= g;
  auto [gg, x, y] = exgcd(k,n);
  x = (x%n + n) %n;
  cout << (x*s %n) << "\n";
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
