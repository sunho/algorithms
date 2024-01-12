#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Modular Integer
// does arithmetics (mod P) automatically
const int MOD = 998244353;
struct mint {
  int x;
  mint() : x(0) {}
  mint(ll val) : x(val % MOD) { x += (x < 0) * MOD; }
};
mint& operator+=(mint& a, mint b) { if ((a.x += b.x) >= MOD) a.x -= MOD; return a; }
mint& operator-=(mint& a, mint b) { if ((a.x -= b.x) < 0) a.x += MOD; return a; }
mint operator*(mint a, mint b) { return mint((ll) a.x * b.x); }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint& operator*=(mint& a, mint b) { return a = a * b; }
mint pow(mint a, ll p) { return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1); }
mint inv(mint a) { return pow(a, MOD - 2); }
mint operator/(mint a, mint b) { return a * inv(b); }

// max query
const int inf = 1e9;
struct seg_tree {
  int n;
  vector<pair<int,int>> bits;
  seg_tree(int n) : n(n), bits((n+1)*2, {inf,inf}) {}

  pair<int,int> combine(pair<int,int> a, pair<int,int> b) { return min(a,b); }
  void update(int k, pair<int,int> x) {
    k += n, bits[k] = x;
    for (k /= 2; k; k /= 2) bits[k] = combine(bits[k*2], bits[k*2+1]);
  }
  pair<int,int> query(int l, int r) {
    pair<int,int> res = {inf,inf};
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l & 1) res = combine(res, bits[l++]);
      if (!(r & 1)) res = combine(res, bits[r--]);
    }
    return res;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  seg_tree st(n);
  for (int i=0;i<n;i++){
    st.update(i, {A[i], i});
  }
  int mn = st.query(0,n-1).second;
  map<pair<int,int>, mint> dp;
  auto f = [&](auto&& self, int l, int r) -> mint {
    if (dp.count({l,r})) {
      return dp[{l,r}];
    }
    int x = st.query(l, r).second;
    int lx = x == l ? -1 : st.query(l, x-1).second;
    int rx = x == r ? -1 : st.query(x+1, r).second;
    int Lmn = st.query(0, l-1).first;
    int Rmn = st.query(r+1, n-1).first;
    mint L = 1, R = 1;
    if (l != x) {
      L += self(self, l, x-1);
    }
    if (r != x) {
      R += self(self, x+1, r);
    }
    mint res = L*R;
    if (A[x] > Rmn) {
      if (l != x) {
        res += self(self, l, x-1);
      }
    }
    if (A[x] > Lmn) {
      if (r != x) {
        res += self(self, x+1, r);
      }
    }
    if (l == x) {
      if (A[x] > Rmn && A[x] < Lmn) {
        res += 1;
      }
    } else if (r == x) {
      if (A[x] > Lmn) {
        res += 1;
      }
    }
    return dp[{l,r}] = res;
  };
  cout << f(f, 0, n-1).x << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
  solve();
}
