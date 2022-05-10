#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
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
  ll n;
  int x;
  cin >> n >> x;
  cin >> P;
  zint A = zint(x);
  vector<int> cycle;
  vector<int> cycle_pos(P,-1);
  cycle.push_back(A.val());
  cycle_pos[A.val()] = 0;
  int cycle_start;
  while (true) {
    A *= A;
    if (cycle_pos[A.val()] != -1) {
      cycle_start = cycle_pos[A.val()];
      break;
    }
    cycle_pos[A.val()] = (int)cycle.size();
    cycle.push_back(A.val());
  }
  ll sum = 0;
  int cycle_size = (int)cycle.size() - cycle_start;
  for(int i=cycle_start;i<(int)cycle.size();i++){
    sum += cycle[i];
  }
  ll ans = 0;
  A = x;
  for(ll i=0;i<min(n,(ll)cycle_start);i++){
    ans += A.val();
    A *= A;
  }
  n -= min(n, (ll)cycle_start);
  ans += sum*(n/cycle_size);
  n %= cycle_size;
  for(int i=0;i<n;i++){
    ans += cycle[cycle_start+i];
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
