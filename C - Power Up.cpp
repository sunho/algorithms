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
  int n;
  cin >> n;
  vector<int> A(n);
  int mx = 0;
  for (int i=0;i<n;i++){
    cin >> A[i];
    mx = max(mx, A[i]);
  }
  mx += 60;
  sort(begin(A),end(A));
  vector<mint> dp(1);
  dp[0] = 1;
  int l = 0;
  for (int a=1;a<=mx;a++) {
    int cnt = 0;
    while (l < n && A[l] == a) {
      cnt++;
      l++;
    }
    int m = (int)dp.size();
    vector<mint> pf(m+1);
    for (int i=0;i<m;i++){
      pf[i+1] = pf[i] + dp[i];
    }
    vector<mint> nxt(cnt+(m-1)/2+1);
    for (int i=0;i<=(m-1)/2;i++) {
      nxt[i+cnt] += pf[m] - pf[min(m, 2*i)];
    }
    dp = nxt;
  }
  cout << accumulate(begin(dp),end(dp),mint(0));
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
