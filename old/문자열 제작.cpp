#include <bits/stdc++.h>

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

using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  const int N = 2e5+1;
  vector<mint> facts(N+1);
  facts[0] = 1;
  for (int i=1;i<=N;i++){
    facts[i] = i * facts[i-1];
  }
  auto choose = [&](int n, int k) -> mint {
    if (k > n) return 0;
    return facts[n]*inv(facts[n-k]*facts[k]);
  };
  mint ans = pow(choose(n,m) * pow(mint(25),n-m), 2);
  for (int i=m+1;i<=n;i++){
    ans += choose(n,i) * pow(mint(25),max(n-i,0)) * choose(n,m) * pow(mint(25),n-m) * 2;
  }
  cout << ans.x << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
