#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Modular Integer
// does arithmetics (mod P) automatically
const int MOD = 1000000007; // 998244353
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
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  const int N = 1e5;
  vector<mint> facts(N+1);
  vector<mint> two_invs(N+1);
  vector<mint> invs(N+1);
  vector<mint> fact_invs(N+1);
  facts[0] = 1;
  for (int i=1;i<=N;i++){
    facts[i] = i*facts[i-1];
  }
  for (int i=0;i<=N;i++){
    fact_invs[i] = inv(facts[i]);
  }
  for (int i=1;i<=N;i++){
    two_invs[i] = inv(pow(mint(2),i));
  }
  for (int i=1;i<=N;i++){
    invs[i] = inv(mint(i));
  }

  int t;
  cin >> t;
  while (t--) {
    ll n,m;
    cin >> n >> m;
    if (m > n) {
      cout << 0 << "\n";
      continue;
    }
    if (m == n) {
      cout << (facts[n-1]/2).v << "\n";
      continue;
    }
    if (m == 0) {
      cout << 1 << "\n";
      continue;
    }
    mint ans = 0;
    for (int i=1;i<=n-m;i++){
      if (m < i) break;
      ans += facts[m-1]*facts[n]*fact_invs[max(n-m-i,1ll)]*fact_invs[i]*two_invs[i]*fact_invs[i-1]*fact_invs[m-i];
    }
    cout << ans.v << "\n";
  }

}
