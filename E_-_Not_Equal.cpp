#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> T power(T a, ll b) { T res = 1; for (; b; b /= 2, a *= a) { if (b % 2) { res *= a; } } return res; }
int P = 1000000007;
struct zint {
  int x;
  // assumes -P <= x <= 2P
  int norm(int x) const { if (x < 0) { x += P; } if (x >= P) { x -= P; } return x; }
  zint(int x = 0) : x(norm(x)) {}
  zint(ll x) : x(norm((int)(x % P))) {}
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

void solve() {
  int n;
  cin >> n;
  vector<int> C(n);
  for(int i=0;i<n;i++) cin >> C[i];
  sort(all(C));
  zint ans = 1;
  for(int i=0;i<n;i++){
    ans *= (C[i]-i);
  }
  cout << ans << "\n";

}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
