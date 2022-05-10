#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> T power(T a, ll b) { T res = 1; for (; b; b /= 2, a *= a) { if (b % 2) { res *= a; } } return res; }
struct zint {
  static const int MOD_DEFAULT = 1000000007; // 1000000007
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

vector<zint> fact;
void solve() {
  int n,k;
  cin >> n >> k;
  cout << fact[n]/(fact[n-k]*fact[k]) << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  const int N = 4e6;
  fact = vector<zint>(N+1);
  fact[0] = 1;
  for(int i=1;i<=N;i++) {
    fact[i] = fact[i-1]*i;
  }

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
