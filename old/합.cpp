#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Modular Integer
// does arithmetics (mod P) automatically
const int MOD = 1000000007; // 998244353
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

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<mint>> S(k+1, vector<mint>(k+1));
  S[0][0] = 1;
  for (int i=1;i<=k;i++){
    for (int j=1;j<=i;j++){
      S[i][j] = S[i-1][j]*j + S[i-1][j-1];
    }
  }
  mint ans = 0;
  // x^k = sun_{i=0}^k {k,i} * (x)_i
  // sum_{x=1}^n x^k = sum_{x=1}^n sun_{i=0}^k {k,i} * (x)_i
  // = sun_{i=0}^k {k,i} sum_{x=1}^n * (x)_i
  // = sum_{i=0}^k {k,i} * (n+1)_{i+1} / {i+1}
  auto fact = [](mint x, int k) {
    mint res = 1;
    while (k--){
      res *= x;
      x-=1;
    }
    return res;
  };
  for (int i=0;i<=k;i++){
    ans += S[k][i] * fact(n+1,i+1) / (i+1);
  }
  cout << ans.x << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
