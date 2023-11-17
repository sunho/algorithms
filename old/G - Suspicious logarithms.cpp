#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using lll = __int128_t;

// Modular Integer
// does arithmetics (mod P) automatically
const int MOD = 1000000007; // 998244353
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

const ll inf = (ll)1e18+1;

int log_k(ll n, int k) {
  if (k == 2) {
    return 63 - __builtin_clzll(n);
  }
  int cnt = 0;
  while (n >= k) {
    cnt++;
    n/=k;
  }
  return cnt;
}

lll ipow(ll n, int k) {
  if (n == 2) {
    return (lll)1 << k;
  }
  lll res = 1;
  while(k){
    if (k&1) res = res*n;
    n = n*n;
    k /= 2;
  }
  return res;
}

mint solve(ll l, ll r) {
  if (l > r) return 0;
  int f = log_k(l, 2);
  lll nxt_f = ipow(2, f+1);
  int g = log_k(l, f);
  lll nxt_g = ipow(f, g+1);
  ll nxt = min({nxt_f, nxt_g, (lll)r+1});
  return (nxt-l)*mint(g) + solve(nxt, r);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q;
  cin >> q;
  while (q--) {
    long long l, r;
    cin >> l >> r;
    cout << solve(l,r).x << "\n";
  }
}
