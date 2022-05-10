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
using zint = g_zint<998244353>;

void solve() {
  // i-d removed i+d+1 added
  // [i-d,i+d]
  // 
  int n, d;
  cin >> n >> d;
  vector<int> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  int M = 1 << (2*d+1);
  int MK = M - 1;
  vector<vector<zint>> dp(n+1, vector<zint>(M));
  dp[0][0] = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < M; j++) {
      if (A[i] == -1) {
        for(int k = -d; k <= d; k++) {
          if (i+k < 0 || i + k >= n) continue;
          int ni = i + k;
          int dd = k + d;
          if (j >> dd & 1) continue;
          int newmask = j | (1 << dd);
          if (i >= d && !(newmask & 1)) continue;
          dp[i+1][(j | (1 << dd)) >> 1] += dp[i][j];
        }
      } else {
        int dd = (A[i] - 1)-i;
        if (dd < -d || dd > d) {
          cout << 0 << "\n";
          return;
        }
        dd += d;
        if (j >> dd & 1) continue;
        int newmask = j | (1 << dd);
        if (i >= d && !(newmask & 1)) continue;
        dp[i+1][(j | (1 << dd)) >> 1] += dp[i][j];
      }
    }
  }

  int fin = 0;
  for(int k = -d; k <= d; k++) {
    int dd = k + d;
    if (n+k < 0 || n + k >= n) continue;
    fin |= (1 << dd); 
  }
  cout << dp[n][fin] << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
