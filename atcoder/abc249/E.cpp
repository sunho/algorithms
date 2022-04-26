#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define _0 first
#define _1 second
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
using zint = g_zint;

void solve() {
  int n;
  cin >> n >> P;
  const int N = 3101;
  vector<vector<zint>> pf(n+2, vector<zint>(n+2, 0));
  vector<vector<zint>> dp(n+1, vector<zint>(n+1, 0));
  dp[0][0] = 1;
  for(int i=1;i<=n;i++) { pf[0][i] = dp[0][0]; }
  array<int,5> pt = {1,10,100,1000,10000};
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      for(int k=1;k<=(int)pt.size()-1;k++){
        int pi = i-(k+1);
        if(pi < 0) continue;
        int s=max(j-pt[k]+1,0);
        int e=max(j-pt[k-1]+1,0);
        dp[i][j] += (pf[pi][e] - pf[pi][s]);
      }
      dp[i][j] *= 25;
      pf[i][j+1] = pf[i][j] + dp[i][j];
    }
  }
  zint ans = 0;
  for(int j=1;j<n;j++){
    ans += dp[j][n];
  }
  ans /= 25;
  ans *= 26;
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
