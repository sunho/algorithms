#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int MOD = 1000000007; // 998244353
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
  cin >> n >> MOD;
  mint ans = 0;
  for (int i=1;i<n;i++){
    if (gcd(i,n) != 1)
      ans += (pow(mint(2), gcd(i, n)-1)-1)*(n-2);
  }
  cout << ans.v << "\n";
}
