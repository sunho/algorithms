#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Modular Integer
// does arithmetics (mod P) automatically
const int MOD = 998244353; // 998244353
struct mint {
  int v;
  mint() : v(0) {}
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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  int a,b,p,q;
  cin >> a >> b >> p >> q;
  vector<mint> T(n+1), A(n+1);
  T[a] = 1, A[b] = 1;
  mint ans = 0;
  mint survive = 1;
  for (int t=0;t<n;t++){
    vector<mint> NT(n+1), NA(n+1);
    for (int i=1;i<=n;i++){
      for (int j=1;j<=p;j++) {
        if (i + j >= n) {
          ans += survive*T[i]/p;
        } else {
          NT[i+j] += T[i]/p;
        }
      }
    }
    survive = 0;
    for (int i=1;i<=n;i++){
      for (int j=1;j<=q;j++) {
        if (i + j < n) {
          NA[i+j] += A[i]/q;
          survive += A[i]/q;
        }
      }
    }
    T = NT;
    A = NA;
  }
  cout << ans.v << "\n";
}
