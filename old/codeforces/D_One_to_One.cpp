#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Modular Integer
// does arithmetics (mod P) automatically
const int MOD = 998244353; // 998244353
struct mint {
  int v;
  mint() : v(0) {}
  int val() { return v; }
  mint(ll v) : v(v % MOD) { v += (v < 0) * MOD; }
};
mint& operator+=(mint& a, mint b) { if ((a.v += b.v) >= MOD) a.v -= MOD; return a; }
mint& operator-=(mint& a, mint b) { if ((a.v -= b.v) < 0) a.v += MOD; return a; }
mint operator*(mint a, mint b) { return mint((ll) a.v * b.v); }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint& operator*=(mint& a, mint b) { return a = a * b; }
mint pow(mint a, ll p) { return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1); }
mint inv(mint a) { return pow(a, MOD - 2); }
mint operator/(mint a, mint b) { return a * inv(b); }

struct union_find {
  int n;
  vector<int> p;
  vector<int> sz;
  union_find(int n) : n(n), p(n), sz(n, 1) {
    iota(begin(p),end(p), 0);
  }
  int leader(int x) {
    if (p[x] == x)
      return x;
    return p[x] = leader(p[x]);
  }
  void unite(int x, int y) {
    int l = leader(x), s = leader(y);
    if (l == s) return;
    if (sz[s] > sz[l]) swap(s,l);
    p[s] = l, sz[l] += sz[s];
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }

  int k = 0;
  int cnt = 0;
  union_find uf(n);
  for (int i=0;i<n;i++){
    if (A[i]!=-1) {
      if (uf.leader(i) != uf.leader(A[i]-1)) {
        uf.unite(i, A[i]-1);
      } else {
        cnt++;
      }
    } else {
      k++;
    }
  }

  mint ans = cnt * pow(mint(n), k);
  vector<mint> dp(k+1);
  dp[0] = 1;
  for (int i=0;i<n;i++){
    if (A[i] != -1) continue;
    int sz = uf.sz[uf.leader(i)];
    for (int j=k;j>=1;j--){
      dp[j] += sz*dp[j-1];
    }
  }
  vector<mint> facts(k+1);
  facts[0] = 1;
  for (int i=1;i<=k;i++) facts[i] = i*facts[i-1];

  for (int i=1;i<=k;i++){
    ans += facts[i-1]*dp[i]*pow(mint(n), k-i);
  }
  cout << ans.val() << "\n";
}
