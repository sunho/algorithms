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
  int n, m;
  cin >> n >> m;
  vector<vector<vector<vector<zint>>>> dp(vector<vector<vector<vector<zint>>>>(3+2, vector<vector<vector<zint>>>(m+1, vector<vector<zint>>(m+1, vector<zint>(m+1)))));
  for(int i=1;i<=m;i++) {
    dp[1][i][0][0] = 1;
  }
  for(int i=1;i<n;i++) {
    vector<vector<vector<vector<zint>>>> next(vector<vector<vector<vector<zint>>>>(3+2, vector<vector<vector<zint>>>(m+1, vector<vector<zint>>(m+1, vector<zint>(m+1)))));
    for(int j=1;j<=3;j++) {
      for(int b0=0;b0<=m;b0++){
        for(int b1=0;b1<=m;b1++){
          for(int b2=0;b2<=m;b2++){
            for(int a=1;a<=m;a++){
              array<int, 3> lis = {b0,b1,b2};
              int idx = lower_bound(lis.begin(), lis.begin()+j, a)-lis.begin();
              if (idx == j) {
                if (j != 3) {
                  lis[j] = a;
                  next[j+1][lis[0]][lis[1]][lis[2]] += dp[j][b0][b1][b2];
                }
              } else {
                lis[idx] = a;
                next[j][lis[0]][lis[1]][lis[2]] += dp[j][b0][b1][b2];
              }
            }
          }
        }
      }
    }
    dp = move(next);
  }
  zint ans = 0;
  for(int b0=1;b0<=m;b0++){
    for(int b1=1;b1<=m;b1++){
      for(int b2=1;b2<=m;b2++){
        ans += dp[3][b0][b1][b2];
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
