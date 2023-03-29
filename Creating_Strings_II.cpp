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
  string s;
  cin >> s;
  int cnt[26] = {};
  for (int i=0;i<s.size();i++){
    cnt[s[i]-'a']++;
  }
  int n = s.size();

  vector<mint> facts(n+1);
  facts[0]=1;
  for (int i=1;i<=n;i++){
    facts[i] = facts[i-1]*i;
  }

  mint ans = facts[n];
  for (int i=0;i<26;i++){
    ans *= inv(facts[cnt[i]]);
  }

  cout << ans.val() << "\n";
}
