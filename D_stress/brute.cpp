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
  set<vector<int>> S;
  vector<int> A(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  seg_tree st(n);
  for (int i=0;i<n;i++){
    st.update(i, {A[i], i});
  }
  S.insert(A);
  auto op = [](vector<int> A, int l, int r) {
    int mn = *min_element(begin(A)+l,begin(A)+r+1);
    vector<int> res;
    for (int i=0;i<A.size();i++){
      if (i < l || i > r) {
        res.push_back(A[i]);
      } else {
        if (A[i] == mn) {
          res.push_back(A[i]);
        }
      }
    }
    return res;
  };
  for (int k=0;k<n;k++) {
    vector<vector<int>> add;
    for (auto& A : S) {
      for (int l=0;l<A.size();l++) {
        for (int r=l;r<A.size();r++) {
          add.push_back(op(A, l ,r));
        }
      }
    }
    for (auto X : add) {
      S.insert(X);
    }
  }
  cout << S.size() << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
  solve();
}
