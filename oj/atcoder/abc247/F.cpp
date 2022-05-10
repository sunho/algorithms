#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

struct DSU {
  vector<int> e;
  vector<int> sz;
  vector<int> p;
  int scc;

  DSU(int N) { 
    e.assign(N, 1);
    sz.assign(N, 0);
    p.assign(N, 0);
    for(int i = 0; i < N; i++) p[i] = i;
    scc = N;
  }

  // get representive component (uses path compression)
  int get(int x) { 
    if (x == p[x]) return x;
    return p[x] = get(p[x]);
  }
  void add(int x) {
    sz[get(x)]++;
  }
  bool same_set(int a, int b) { return get(a) == get(b); }
  int size(int x) { return e[get(x)]; }
  bool unite(int x, int y) {  // union by size
    x = get(x), y = get(y);
    if (x == y) return false;
    if (e[x] < e[y]) 
      swap(x, y);
    e[x] += e[y];
    sz[x] += sz[y];
    p[y] = x;
    scc--;
    return true;
	}
};

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
  vector<int> A(n), B(n);
  DSU dsu(n);
  for(int i=0;i<n;i++) {
    cin >> A[i];
    --A[i];
  }
  for(int i=0;i<n;i++) {
    cin >> B[i];
    --B[i];
  }
  for(int i=0;i<n;i++){
    dsu.unite(A[i], B[i]);
    dsu.add(A[i]);
  }
  vector<zint> f(n+1);
  f[1] = 2;
  f[2] = 3;
  for(int i=3;i<=n;i++){
    f[i] = f[i-1] + f[i-2];
  }
  vector<zint> L(n+1);
  L[0] = 1;
  L[1] = 1;
  L[2] = 3;
  L[3] = 4;
  for(int i=4;i<=n;i++) {
    L[i] = f[i-1] + f[i-3];
  }
  
  zint ans = 1;
  vector<bool> visited(n);
  for(int i=0;i<n;i++){
    int p = dsu.get(i);
    int sz = dsu.sz[p];
    int set_sz = dsu.e[p];
    if (!visited[p]) {
      visited[p] = true;
      ans *= L[set_sz];
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
