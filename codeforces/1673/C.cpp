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

struct fenwick_tree {
  // [-bias, n - bias)
  fenwick_tree(int n) : sums(n) {}
  void update(int pos, zint dif) { // a[pos] += dif
    for (; pos < (int)sums.size(); pos |= pos + 1) sums[pos] += dif;
  }
  zint query(int pos) { // sum of values in [0, pos)
    zint res = 0;
    for (; pos > 0; pos &= pos - 1) res += sums[pos-1];
    return res;
  }
  zint query(int l, int r) { // sum of values in [l, r)
    return query(r) - query(l);
  }
private:
  vector<zint> sums;
};
vector<fenwick_tree> dp;
vector<int> palins;

void solve() {
  int n;
  cin >> n;
  int m = (int)palins.size();
  zint ans = 0;
  for(int i=0;i<m;i++){
    ans += dp[n].query(i,i+1);
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  auto is_palin = [&](int n) {
    vector<int> a;
    while(n) {
      a.push_back(n%10);
      n /= 10;
    }
    int m = (int)a.size();
    for (int i=0;i<m/2;i++) {
      if (a[i] != a[m-1-i]) {
        return false;
      }
    }
    return true;
  };

  const int N = 4e4;
  for(int i = 1; i<=N;i++) {
    if (is_palin(i)) palins.push_back(i);
  }

  int m = (int)palins.size();
  dp = vector<fenwick_tree>(N+1, fenwick_tree(m));
  dp[0].update(0, 1);
  for(int i=1;i<=N;i++){
    for(int j=0;j<m;j++) {
      if (i - palins[j] >= 0) {
        dp[i].update(j, dp[i-palins[j]].query(0, j+1));
      }
    }
  }

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
