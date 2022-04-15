#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
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
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i=0;i<n;i++) {
    cin >> A[i];
  }
  sort(all(A));
  vector<zint> fact(n+1);
  fact[0] = 1;
  for(int i=1;i<=n;i++) {
    fact[i]=fact[i-1]*i;
  }

  vector<zint> ifact(n+1);
  ifact[1] = n;
  for(int i=2;i<=n;i++) {
    ifact[i]=ifact[i-1]*(n-i+1);
  }

  int maxi = -1;
  int maxin = 0;
  int smaxi = -1;
  int q = 0;
  for(int i=n-1;i>=0;i--) {
    if (maxi == -1) {
      maxi = A[i];
    }
    if (maxi == A[i]) {
      maxin++;
      continue;
    }
    if (smaxi == -1) {
      smaxi = A[i];
    }
    if(smaxi == A[i]) {
      q++;
    }
  }
  if (q == 0) {
    cout << fact[n] << "\n";
    return;
  }
  if (maxin != 1) {
    cout << fact[n] << "\n";
    return;
  }
  if (maxi - smaxi > 1) {
    cout << 0 << "\n";
    return;
  }
  zint ans = fact[n];
  zint exc = 0;
  for(int i=1;i<=n-q;i++) { 
    exc += fact[n-i] / fact[n-i-q];
  }
  exc *= fact[n-1-q];
  ans -= exc;
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
