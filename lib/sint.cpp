template<ll N> struct g_sint {
  ll x;
  static ll norm(ll x) { if (x > N) return N; return x; }
  g_sint(ll x) : x(x) {}
  ll val() const { return x; }
  g_sint operator-() const { return g_sint(norm(-x)); }
  g_sint& operator*=(const g_sint& rhs) { if (rhs.x > 0 && x > N / rhs.x) { x = N; return *this; } x *= rhs.x; return *this; }
  g_sint& operator+=(const g_sint& rhs) { x = norm(x + rhs.x); return *this; }
  g_sint& operator-=(const g_sint& rhs) { x -= rhs.x; return *this; }
  g_sint& operator/=(const g_sint& rhs) { x /= rhs.x; return *this; }
  friend g_sint operator*(const g_sint& lhs, const g_sint& rhs) { g_sint res = lhs; res *= rhs; return res; }
  friend g_sint operator+(const g_sint& lhs, const g_sint& rhs) { g_sint res = lhs; res += rhs; return res; }
  friend g_sint operator-(const g_sint& lhs, const g_sint& rhs) { g_sint res = lhs; res -= rhs; return res; }
  friend g_sint operator/(const g_sint& lhs, const g_sint& rhs) { g_sint res = lhs; res /= rhs; return res; }
  friend ostream& operator<<(ostream& out, const g_sint& rhs) { out << rhs.val(); return out; }
  friend istream& operator>>(istream& in, g_sint& rhs) { ll x; in >> x; rhs = g_sint(x); return in; }
};
using sint = g_sint<1000000000000000000>;