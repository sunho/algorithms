#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> T power(T a, ll b) { T res = 1; for (; b; b /= 2, a *= a) { if (b % 2) { res *= a; } } return res; }
template<int P> struct g_zint {
  int x;
  // assumes -P <= x <= 2P
  static int norm(int x) { if (x < 0) { x += P; } if (x >= P) { x -= P; } return x; }
  g_zint(int x = 0) : x(norm(x)) {}
  g_zint(ll x) : x(norm(x % P)) {}
  int val() const { return x; }
  g_zint operator-() const { return g_zint(norm(P - x)); }
  g_zint inv() const { assert(x != 0); return power(*this, P - 2); }
  g_zint& operator*=(const g_zint& rhs) { x = ll(x) * rhs.x % P; return *this; }
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
using zint = g_zint<998244353>;


void solve() {
  int n,m,k;
  cin >> n >> m >> k;
  vector<vector<zint>> dp(n+1, vector<zint>(n*m+1));
  dp[0][0] = 1;
  for(int i=0;i<n;i++){
    for(int j=0;j<n*m;j++) {
      for(int z=1;z<=m;z++) {
        if (j+z <= n*m) {
          dp[i+1][j+z] += dp[i][j];
        }
      }
    }
  }
  zint ans = 0;
  for(int i=0;i<=k;i++){
    ans += dp[n][i];
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
