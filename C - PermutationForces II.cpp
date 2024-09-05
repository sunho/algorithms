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


void solve() {
  int n, s;
  cin >> n >> s;
  vector<int> A(n);
  vector<int> B(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  for (int i=0;i<n;i++){
    cin >> B[i];
  }
  int mx_diff = 0;
  set<int> A2, B2;
  for (int i=1;i<=n;i++) {
    A2.insert(i);
    B2.insert(i);
  }
  for (int i=0;i<n;i++){
    if (B[i] != -1) {
      mx_diff = max(mx_diff, A[i]-B[i]);
      A2.erase(A[i]);
      B2.erase(B[i]);
    }
  }
  if (mx_diff > s) {
    cout << 0 << "\n";
    return;
  }
  dbg(A2)
  dbg(B2)
  mint ans = 1;
  int avail = 0;
  for (auto it = A2.rbegin(); it != A2.rend(); ++it) {
    int a = *it;
    while (!B2.empty() && a - *--B2.end() <= s) {
      avail++;
      B2.erase(--B2.end());
    }
    ans *= avail;
    avail--;
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
