#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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
mint fact(int n) {
  if (facts[0].val() == 0) {
    facts[0] = 1;
    for (int i=1;i<=FN;i++) {
      facts[i] = i * facts[i-1];
    }
  }
  return facts[n];
}
mint choose(int n, int k) {
  return fact(n)/(fact(n-k)*fact(k));
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> A(n);
  int cnt = 0;
  for (int i=0;i<n;i++){
    cin >> A[i];
    cnt += A[i];
  }
  int mm = min(n,m+1);
  vector<mint> dp(mm+1);
  dp[0] = 1;
  for (int i=0;i<n;i++){
    vector<mint> nxt(mm+1);
    for (int j=0;j<=mm;j++){
      if (A[i] == 1) {
        if (j+1<=mm)
          nxt[j+1] += dp[j];
      } else {
        if (j+1<=mm)
          nxt[j+1] += max(m-j,0)*dp[j];
        nxt[j] += j*dp[j];
      }
    }
    dp = nxt;
  }
  mint ans = 0;
  for (int i=0;i<=mm;i++){
    ans += dp[i];
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
