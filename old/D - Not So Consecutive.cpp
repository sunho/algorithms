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

struct fenwick_tree {
  int n;
  vector<mint> bits;
  fenwick_tree(int n) : n(n), bits(n + 1) {}
  void add(int v, mint delta) {
    for (++v; v <= n; v += v & (-v))
      bits[v] += delta;
  }
  void update(int v, mint delta) {
    add(v, delta);
  }
  mint query(int r) {
    mint res = 0;
    for (++r; r > 0; r -= r & (-r))
      res += bits[r];
    return res;
  }
  mint query(int l, int r) { return query(r) - query(l - 1); }
};


void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
    if (A[i] >= 1)
      A[i]--;
  }
  vector<vector<mint>> dp(n+1, vector<mint>(n));
  vector<fenwick_tree> dp2(n, fenwick_tree(n+1));
  int last = 0;
  int last_x = n;
  int recent = 0;
  if (A[0] == -1) {
    for (int i=0;i<n;i++){
      dp[1][i] = 1;
      dp2[i].update(1,1);
    }
  } else {
    dp[1][A[0]] = 1;
    dp2[A[0]].update(1,1);
    last_x = A[0];
    last = 1;
    recent = 1;
  }
  for (int i=2;i<=n;i++){
    mint sum = 0;
    for (int j=0;j<n;j++){
      sum += dp[i-1][j];
    }
    for (int j=0;j<n;j++){
      if (A[i-1] == -1 || A[i-1] == j)
        dp2[j].update(i, sum-dp[i-1][j]);
    }
    for (int j=0;j<n;j++){
      if (A[i-1] == -1 || A[i-1] == j) {
        dp[i][j] = dp2[j].query(max(i-j,j == last_x?last:recent), i);
      }
    }
    if (A[i-1] != -1) {
      if (A[i-1] != last_x) {
        last = recent;
        last_x = A[i-1];
        recent = i;
      } else {
        recent = i;
      }
    }
  }
  mint ans = 0;
  for (int i=0;i<n;i++){
    ans += dp[n][i];
  }
  cout << ans;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
