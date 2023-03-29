#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Modular Integer
// does arithmetics (mod P) automatically
int MOD = 1000000007; // 998244353
struct mint {
 	int v=0; 
  int val() { return v; }
  mint() = default;
	mint(ll v) : v(v % MOD) { v += (v < 0) * MOD; }
};
mint& operator+=(mint& a, mint b) { if ((a.v += b.v) >= MOD) a.v -= MOD; return a; }
mint& operator-=(mint& a, mint b) { if ((a.v -= b.v) < 0) a.v += MOD; return a; }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint operator*(mint a, mint b) { return mint((ll) a.v * b.v); }
mint& operator*=(mint& a, mint b) { return a = a * b; }
mint pow(mint a, ll p) { return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1); }
mint inv(mint a) { return pow(a, MOD - 2); }

int main() {
  const int N = 1e6;
  vector<mint> facts(N+1);
  facts[0] = 1;
  for (int i=1;i<=N;i++){
    facts[i] = facts[i-1]*i;
  }
  int n;
  cin >> n;
  while (n--){
    int a,b;
    cin >> a >> b;
    cout << (facts[a]*inv(facts[b]*facts[a-b])).val() << "\n";
  }
}
