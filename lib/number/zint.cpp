// mod int
// inv() and division doesn't work if P is not prime
template<class T> T power(T a, ll b) { T res = 1; for (; b; b /= 2, a *= a) { if (b % 2) { res *= a; } } return res; }

struct zint {
  static const int MOD_DEFAULT = 998244353; // 1000000007
  int P;
  int x;
  // assumes -P <= x <= 2P
  int norm(int x) const { if (x < 0) { x += P; } if (x >= P) { x -= P; } return x; }
  zint(int x = 0, int P = MOD_DEFAULT) : P(P), x(norm(x)) {}
  zint(ll x, int P = MOD_DEFAULT) : P(P), x(norm((int)(x % P))) {}
  int val() const { return x; }
  zint operator-() const { return zint(norm(P - x)); }
  zint inv() const { assert(x != 0); return power(*this, P - 2); }
  zint& operator*=(const zint& rhs) { x = (int)(ll(x) * rhs.x % P); return *this; }
  zint& operator+=(const zint& rhs) { x = norm(x + rhs.x); return *this; }
  zint& operator-=(const zint& rhs) { x = norm(x - rhs.x); return *this; }
  zint& operator/=(const zint& rhs) { return *this *= rhs.inv();}
  friend zint operator*(const zint& lhs, const zint& rhs) { zint res = lhs; res *= rhs; return res; }
  friend zint operator+(const zint& lhs, const zint& rhs) { zint res = lhs; res += rhs; return res; }
  friend zint operator-(const zint& lhs, const zint& rhs) { zint res = lhs; res -= rhs; return res; }
  friend zint operator/(const zint& lhs, const zint& rhs) { zint res = lhs; res /= rhs; return res; }
  friend ostream& operator << (ostream& out, const zint& rhs) { out << rhs.val(); return out; }
  friend istream& operator >> (istream& in, zint& rhs) { ll x; in >> x; rhs = zint(x); return in; }
};