#include <bits/stdc++.h>
using namespace std;
using ll = long long;


// Modular Integer
// does arithmetics (mod P) automatically
const int MOD = 1000000007; // 998244353
template<class T> T power(T a, ll b) { T res = 1; for (; b; b /= 2, a *= a) { if (b % 2) { res *= a; } } return res; }
struct mint {
  int x;
  static int norm(int x) { if (x < 0) { x += MOD; } if (x >= MOD) { x -= MOD; } return x; }
  int val() const { return x; }
  mint(int x = 0) : x(norm(x)) {}
  mint(ll x) : x(norm((int)(x % MOD))) {}
  mint operator-() const { return mint(norm(MOD - x)); }
  mint inv() const { assert(x != 0); return power(*this, MOD - 2); }
  mint& operator*=(const mint& rhs) { x = (int)(ll(x) * rhs.x % MOD); return *this; }
  mint& operator+=(const mint& rhs) { x = norm(x + rhs.x); return *this; }
  mint& operator-=(const mint& rhs) { x = norm(x - rhs.x); return *this; }
  mint& operator/=(const mint& rhs) { return *this *= rhs.inv();}
  friend mint operator*(const mint& lhs, const mint& rhs) { mint res = lhs; res *= rhs; return res; }
  friend mint operator+(const mint& lhs, const mint& rhs) { mint res = lhs; res += rhs; return res; }
  friend mint operator-(const mint& lhs, const mint& rhs) { mint res = lhs; res -= rhs; return res; }
  friend mint operator/(const mint& lhs, const mint& rhs) { mint res = lhs; res /= rhs; return res; }
  friend ostream& operator << (ostream& out, const mint& rhs) { out << rhs.val(); return out; }
  friend istream& operator >> (istream& in, mint& rhs) { ll x; in >> x; rhs = mint(x); return in; }
};
mint inv(mint a) { return power(a, MOD - 2); }

const int inf = 1e9;
template<class T, T def, auto combine>
struct seg_tree {
  int n;
  vector<T> bits;
  seg_tree(int n) : n(n), bits((n+1)*2, def) {}
  void set(int k, T x) {
    k += n, bits[k] = x;
    for (k /= 2; k; k /= 2) bits[k] = combine(bits[k*2], bits[k*2+1]);
  }
  T get(int i) {
    return bits[i+n];
  }
  T query(int l, int r) {
    T res = def;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l & 1) res = combine(res, bits[l++]);
      if (!(r & 1)) res = combine(res, bits[r--]);
    }
    return res;
  }
};

pair<int,int> combine_max(pair<int,int> a, pair<int,int> b) { return max(a,b); }
using max_seg_tree = seg_tree<pair<int,int>,make_pair(-inf,-inf),combine_max>;

void solve() {
  int n, m;
  cin >> n >> m;
  max_seg_tree st(n);
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    st.set(i, {a,-i});
  }
  auto f = [&](auto&& self, int l, int r) -> vector<mint> {
    vector<mint> res(m+1);
    if (l > r) {
      res[0] = 1;
      return res;
    }
    int mid = -st.query(l,r).second;
    auto ldp = self(self, l,mid-1), rdp = self(self, mid+1,r);
    mint L = 0, R = 0;
    for (int i=0;i<=m;i++){
      R += rdp[i];
      res[i] = L*R;
      L += ldp[i];
    }
    return res;
  };
  auto res = f(f, 0, n-1);
  mint ans = 0;
  for (mint a : res) {
    ans += a;
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
