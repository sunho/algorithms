#include <bits/stdc++.h>
#include <unordered_map>
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

const int N = 3e6;

vector<mint> facts(N+1);
vector<mint> inv_facts(N+1);

mint choose(int n, int k) {
  return facts[n]*inv_facts[k]*inv_facts[n-k];
}

mint binom(int r, int g, int b, int k, int k2) {
  return facts[r+g+b+k+k2]*inv_facts[g]*inv_facts[b]*inv_facts[r]*inv_facts[k]*inv_facts[k2];
}

mint f(int r, int g, int b, int k, int k2) {
  mint res = binom(r,g,b,k,k2);
  if (min(r,g) >= 1)
    res -= f(r-1,g-1,b,k, k2+1);
  return res;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  facts[0] = 1;
  for (int i=1;i<=N;i++){
    facts[i] = i*facts[i-1];
  }
  for (int i=0;i<=N;i++){
    inv_facts[i] = inv(facts[i]);
  }

  int r,g,b,k;
  cin >> r >> g >> b >> k;

  mint ans = f(r-k,g-k,b,k,0);
  cout << ans.v << "\n";

}
