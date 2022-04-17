#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> T power(T a, ll b) { T res = 1; for (; b; b /= 2, a *= a) { if (b % 2) { res *= a; } } return res; }
int P;
struct g_zint {
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
using zint = g_zint;

zint dp[2][3009][3];
void solve() {
  int n;
  cin >> n;
  cin >> P;
  
  dp[0][0][0] = 1;
  dp[0][1][2] = 1;
  for(int i=0;i<n-1;i++){
    for(int j=0;j<=n-1;j++) for(int k =0;k<3;k++) dp[(i^1)&1][j][k] = 0;
    for(int j=0;j<=min(i+1,n-1);j++) {
      for(int k : {0,1}) {
        dp[(i^1)&1][j][0] += dp[i&1][j][k];
        dp[(i^1)&1][j+1][0] += dp[i&1][j][k];
        dp[(i^1)&1][j+1][0] += dp[i&1][j][k];
        dp[(i^1)&1][j+1][1] += dp[i&1][j][k];
        dp[(i^1)&1][j+2][2] += dp[i&1][j][k];
        dp[(i^1)&1][j+2][2] += dp[i&1][j][k];
      }
      dp[(i^1)&1][j][0] += dp[i&1][j][2];
      dp[(i^1)&1][j+1][2] += dp[i&1][j][2];
    }
  }
  for(int i=1;i<=n-1;i++) {
    zint ans = 0;
    for(int k=0;k<2;k++){
      ans += dp[(n-1)&1][i][k];
    }
    cout << ans << " ";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
