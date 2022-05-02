#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> T power(T a, ll b) { T res = 1; for (; b; b /= 2, a *= a) { if (b % 2) { res *= a; } } return res; }
template<int P> struct g_zint {
  int x;
  // assumes -P <= x <= 2P
  static int norm(int x) { if (x < 0) { x += P; } if (x >= P) { x -= P; } return x; }
  g_zint(int x = 0) : x(norm(x)) {}
  g_zint(ll x) : x(norm((int)(x % P))) {}
  int val() const { return x; }
  g_zint operator-() const { return g_zint(norm(P - x)); }
  g_zint inv() const { assert(x != 0); return power(*this, P - 2); }
  g_zint& operator*=(const g_zint& rhs) { x = (int)(ll(x) * rhs.x % P); return *this; }
  g_zint& operator+=(const g_zint& rhs) { x = norm(x + rhs.x); return *this; }
  g_zint& operator-=(const g_zint& rhs) { x = norm(x - rhs.x); return *this; }
  g_zint& operator/=(const g_zint& rhs) { return *this *= rhs.inv();}
  friend g_zint operator*(const g_zint& lhs, const g_zint& rhs) { g_zint res = lhs; res *= rhs; return res; }
  friend g_zint operator+(const g_zint& lhs, const g_zint& rhs) { g_zint res = lhs; res += rhs; return res; }
  friend g_zint operator-(const g_zint& lhs, const g_zint& rhs) { g_zint res = lhs; res -= rhs; return res; }
  friend g_zint operator/(const g_zint& lhs, const g_zint& rhs) { g_zint res = lhs; res /= rhs; return res; }
  friend ostream& operator << (ostream& out, const g_zint& rhs) { out << rhs.val(); return out; }
  friend istream& operator >> (istream& in, g_zint& rhs) { ll x; in >> x; rhs = g_zint(x); return in; }
};
using zint = g_zint<1000000007>;

void solve() {
  ll b_start, b_dif, b_size; 
  ll c_start, c_dif, c_size;
  cin >> b_start >> b_dif >> b_size;
  cin >> c_start >> c_dif >> c_size;
  auto contains = [&](ll n, ll start, ll dif, ll size) {
    if (n < start) return false;
    if ((n - start) % dif != 0) return false;
    return (n-start)/dif < size;
  };
  if (!contains(c_start, b_start, b_dif, b_size) || !contains(c_start+(c_size-1)*c_dif, b_start, b_dif, b_size) || c_dif % b_dif != 0) {
    cout << 0 << "\n";
    return;
  }
  set<ll> counted;
  zint ans = 0;
  for (ll k = 1; k*k <= c_dif; k++) {
    if (c_dif % k != 0) continue;
    for (ll a_dif : {k, c_dif/k}) {
      if (counted.count(a_dif)) continue;
      ll l = lcm(a_dif, b_dif);
      ll wide = (c_size-1)*c_dif;
      if (l % c_dif != 0 && wide > l) continue;

      if (!contains(c_start - l, b_start, b_dif, b_size) ||
        !contains(c_start + c_dif*(c_size-1) + l, b_start, b_dif, b_size)) {
        cout << -1 << "\n";
        return;
      }
      zint aa = l/a_dif;
      ans += aa*aa;
      counted.insert(a_dif);
    }
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
