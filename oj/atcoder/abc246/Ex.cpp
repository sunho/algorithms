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

struct matrix {
  array<array<zint, 3>, 3> m{};
  matrix() {
    m[0][0] = 1;
    m[1][1] = 1;
    m[2][2] = 1;
  }
  friend const matrix operator*(const matrix& lhs, const matrix& rhs) {
    matrix res;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        res.m[i][j]=0;
        for (int k = 0; k < 3; k++) {
          res.m[i][j] += lhs.m[i][k] * rhs.m[k][j];
        }
      }
    }
    return res;
  }
  friend const array<zint,3> operator*(const matrix& lhs, const array<zint,3>& rhs) {
    array<zint,3> res{};
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        res[j] += lhs.m[j][k] * rhs[k];
      }
    }
    return res;
  }
};

struct seg_tree {
  seg_tree(int n, int bias=0) : n(n), bias(bias), a(n*4) {
  }
  struct node {
    matrix m;
    void update(matrix v) {
      m = v;
    }
  };
  node merge(const node &x, const node &y) {
    node ret;
    ret.m = x.m * y.m;
    return ret;
  }
  template <typename... V>
  void update(int pos, int l, int r, int rt, const V&... v) {
    if(l == r) {
      a[rt].update(v...);
      return;
    }
    int m = (l + r) / 2;
    if(pos <= m) update(pos, l, m, rt*2, v...);
    else update(pos, m+1, r, rt*2+1, v...);
    a[rt] = merge(a[rt*2], a[rt*2+1]);
  }
  template <typename... V>
  void update(int pos, const V&... v) {
    pos += bias;
    update(pos, 0, n - 1, 1, v...);
  }
  node query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) return a[rt];
    node ret;
    int m = (l + r) / 2;
    if(L <= m) ret = merge(ret, query(L, R, l, m, rt*2));
    if(m < R) ret = merge(ret, query(L, R, m+1, r, rt*2+1));
    return ret;
  }
  matrix query(int L, int R) {
    L += bias, R += bias;
    return query(L, R-1, 0, n - 1, 1).m;
  }

  int n;
  int bias;
  vector<node> a;
};
// 1101
// 1 1
// 11 2
// 0 10 110 3
// 111 1101 101 01
// s = numbers of subsequences ends with 'a'
// 1
// s0 dp[i][1] = dp[i-1][0] + dp[i-1][1] + 1
// s1 dp[i][0] = dp[i-1][0] + dp[i-1][1] + 1
// s? dp[i][1] = dp[i-1][0] + dp[i-1][1] + 1
//    dp[i][0] = dp[i-1][0] + dp[i-1][1] + 1
// [x]
// [y]
// [1]
//
// [1 1 1]
// [0 1 0]
// [0 0 1]
//
// [1 0 0]
// [1 1 1]
// [0 0 1]
//
// [1 1 1]
// [1 1 1]
// [0 0 1]

void solve() {
  matrix m0;
  m0.m[0][0] = 1; m0.m[0][1] = 1; m0.m[0][2] = 1;
  matrix m1;
  m1.m[1][0] = 1; m1.m[1][1] = 1; m1.m[1][2] = 1;
  matrix mq;
  mq.m[0][0] = 1; mq.m[0][1] = 1; mq.m[0][2] = 1; mq.m[1][0] = 1; mq.m[1][1] = 1; mq.m[1][2] = 1;

  int n,q;
  cin >> n >> q;
  seg_tree st(n);
  string s;
  cin >> s;
  for(int i=0;i<n;i++){
    if (s[i] == '1') {
      st.update(i,m1);
    } 
    if (s[i] == '0') {
      st.update(i,m0);
    }
    if (s[i] == '?') {
      st.update(i,mq);
    }
  }

  while (q--) {
    int t;
    char c;
    cin >> t >> c;
    --t;
    if (c == '1') {
      st.update(t,m1);
    } else if (c == '0') {
      st.update(t,m0);
    } else {
      st.update(t,mq);
    }
    array<zint,3> dp = {0,0,1};
    dp = st.query(0,n) * dp;
    cout << dp[0] + dp[1] << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
