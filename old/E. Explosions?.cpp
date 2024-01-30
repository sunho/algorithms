#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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

// max query
const int inf = 1e9;
struct seg_tree {
  int n;
  vector<int> bits;
  seg_tree(int n) : n(n), bits((n+1)*2, -inf) {}

  int combine(int a, int b) { return min(a,b); }
  void update(int k, int x) {
    k += n, bits[k] = x;
    for (k /= 2; k; k /= 2) bits[k] = combine(bits[k*2], bits[k*2+1]);
  }
  int query(int l, int r) {
    int res = inf;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l & 1) res = combine(res, bits[l++]);
      if (!(r & 1)) res = combine(res, bits[r--]);
    }
    return res;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  seg_tree st(n);
  ll sum = 0;
  for (int i=0;i<n;i++) {
    cin >> A[i];
    sum += A[i];
    st.update(i,A[i]+i);
  }
  auto go = [&]() {
    vector<ll> dp(n+1);
    for (int i=n-1;i>=0;i--) {
      int ng = i, ok = min(i+A[i],n);
      auto check = [&](int nxt) {
        return A[i] + i >= st.query(i+1,nxt);
      };
      while (ok-ng>1) {
        int mid = ok + ng >> 1;
        if (check(mid)) ok = mid;
        else ng = mid;
      }
      int d = ok-i;
      dp[i] = (ll)(2*A[i]-d+1)*(d)/2 + (check(ok) ? dp[ok] : 0);
    }
    return dp;
  };
  auto dp = go();
  reverse(begin(A),end(A));
  for (int i=0;i<n;i++){
    st.update(i,A[i]+i);
  }
  auto dp2 = go();
  reverse(begin(A),end(A));
  ll ans = 1e18;
  for (int i=0;i<n;i++){
    ll cost = dp[i] + dp2[n-1-i] - A[i];
    ans = min(ans, sum - cost + A[i]);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
