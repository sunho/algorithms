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

const int N = 2e5;
mint facts[N+1];
mint inv_facts[N+1];

mint choose(int n, int k) {
  if (n < k) return 0;
  return facts[n]*inv_facts[n-k]*inv_facts[k];
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

  int n,m,k;
  cin >> n >> m >> k;
  
  vector<int> deg(n);

  for (int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    deg[u]++;
    deg[v]++;
  }
  int even = 0, odd = 0;
  for (int i=0;i<n;i++){
    if (deg[i] % 2) odd++;
    else even++;
  }
  int kk = min(k/2, odd/2);
  mint ans = 0;
  for (int i=0;i<=kk;i++){
    ans += choose(odd, 2*i)*choose(even,k-2*i);
  }
  cout << ans.v << "\n";
    
}
