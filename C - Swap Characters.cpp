#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifndef ONLINE_JUDGE
#include "lib/debug.h"
#else
#define dbg(x...) 
#endif


// Modular Integer
// does arithmetics (mod P) automatically
const int MOD = 998244353;
template<class T> T power(T a, ll b) { T res = 1; for (; b; b /= 2, a *= a) { if (b % 2) { res *= a; } } return res; }
struct mint {
  int x;
  static int norm(int x) { if (x < 0) { x += MOD; } if (x >= MOD) { x -= MOD; } return x; }
  int val() const { return x; }
  mint(int x = 0) : x(norm(x)) {}
  mint(ll x) : x(norm((int)(x % MOD))) {}
  mint operator-() const { return mint(norm(MOD - x)); }
  mint inv() const { assert(x != 0); return power(*this, MOD - 2); }
  mint& operator*=(const mint& rhs) { x = (int)(ll(x) * rhs.x % MOD); return *this; }
  mint& operator+=(const mint& rhs) { x = norm(x + rhs.x); return *this; }
  mint& operator-=(const mint& rhs) { x = norm(x - rhs.x); return *this; }
  mint& operator/=(const mint& rhs) { return *this *= rhs.inv();}
  friend mint operator*(const mint& lhs, const mint& rhs) { mint res = lhs; res *= rhs; return res; }
  friend mint operator+(const mint& lhs, const mint& rhs) { mint res = lhs; res += rhs; return res; }
  friend mint operator-(const mint& lhs, const mint& rhs) { mint res = lhs; res -= rhs; return res; }
  friend mint operator/(const mint& lhs, const mint& rhs) { mint res = lhs; res /= rhs; return res; }
  friend ostream& operator << (ostream& out, const mint& rhs) { out << rhs.val(); return out; }
  friend istream& operator >> (istream& in, mint& rhs) { ll x; in >> x; rhs = mint(x); return in; }
};
mint inv(mint a) { return power(a, MOD - 2); }

const int FN = 3e5;
vector<mint> facts(FN+1);
vector<mint> ifacts(FN+1);
mint choose(int n, int k) {
  if (facts[0].val() == 0) {
    facts[0] = 1;
    for (int i=1;i<=FN;i++) {
      facts[i] = i * facts[i-1];
    }
    ifacts[0] = 1;
    for (int i=1;i<=FN;i++) {
      ifacts[i] = inv(facts[i]);
    }
  }
  return facts[n]*ifacts[n-k]*ifacts[k];
}

mint g(array<int,3> cnt, array<array<int,3>,3> C) {
  return choose(cnt[0], C[0][1])*choose(cnt[0]-C[0][1],C[0][2])
  *choose(cnt[1], C[1][0])*choose(cnt[1]-C[1][0],C[1][2])
  *choose(cnt[2], C[2][0])*choose(cnt[2]-C[2][0],C[2][1]);
}

void solve() {
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  array<int,3> cnt{};
  for (int i=0;i<n;i++){
    if (s[i] == 'A') cnt[0]++;
    if (s[i] == 'B') cnt[1]++;
    if (s[i] == 'C') cnt[2]++;
  }
  int mn = min({cnt[0], cnt[1], cnt[2]});
  mint ans = 0;
  for (int x=0;x<=k;x++){
    for (int a=0;a<=k;a++) {
      for (int b=0;b<=k;b++){
        for (int c=0;c<=k;c++){
          auto cnt2 = cnt;
          cnt2[0]-=x,cnt2[1]-=x,cnt2[2]-=x;
          cnt2[0]-=a,cnt2[1]-=a;
          cnt2[1]-=b,cnt2[2]-=b;
          cnt2[2]-=c,cnt2[0]-=c;
          if (a+b+c+2*x > k || cnt2[0] < 0 || cnt2[1] < 0 || cnt2[2] < 0) continue;
          dbg(a,b,c,x)
          array<array<int,3>,3> C{};
          C[0][1] += a;
          C[1][0] += a;
          C[1][2] += b;
          C[2][1] += b;
          C[2][0] += c;
          C[0][2] += c;
          dbg(C)
          auto C2 = C;
          C2[0][1] += x;
          C2[1][2] += x;
          C2[2][0] += x;
          ans += g(cnt, C2);
          C2 = C;
          C2[0][2] += x;
          C2[1][0] += x;
          C2[2][1] += x;
          if (x != 0) ans += g(cnt, C2);
        }
      }
    }
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
