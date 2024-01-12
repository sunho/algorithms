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

struct fenwick_tree {
  int n;
  vector<mint> bits;
  fenwick_tree(int n) : n(n), bits(n + 1) {}
  void update(int v, int delta) {
    for (++v; v <= n; v += v & (-v))
      bits[v] += delta;
  }
  mint query(int r) {
    mint res = 0;
    for (++r; r > 0; r -= r & (-r))
      res += bits[r];
    return res;
  }
  mint query(int l, int r) { return query(r) - query(l - 1); }
};

void solve() {
  int n,k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<int> B(k);
  for (int i=0;i<k;i++){
    cin >> B[i];
  }
  fenwick_tree ft(2*n+1);
  mint ans = 0;
  for (int i=n-1;i>=0;i--){
    int aa = A[i];
    int z = 0;
    while (z < k) {
      int kk = 0;
      int a = aa;
      bool last = aa*2 > (4*n);
      while (a / (1<<kk) > 0) {
        int r = min(a / (1<<kk), 2*n);
        kk++;
        int l = min(a / (1<<kk)+1, 2*n);
        int y = min(kk,k);
        if (last) {
          int m = k-z;
          int t = min(k-y+1,m);
          ans += ft.query(l,r) * ((mint)(2*y+t-1)*t/2+(mint)k*(m-t));
        } else {
          ans += ft.query(l,r) * y;
        }
      }
      aa *= 2;
      z++;
      if (last) {
        break;
      }
    }
    ft.update(A[i], 1);
  }
  fenwick_tree ft2(k+1);
  for (int i=k-1;i>=0;i--) {
    ans += n*ft2.query(0,B[i]);
    ft2.update(B[i], 1);
  }
  cout << ans.x << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
