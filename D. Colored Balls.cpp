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
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  int m = 0;
  for (int i=0;i<n;i++){
    m += A[i];
  }
  sort(rbegin(A),rend(A));
  vector<mint> dp1(m+1);
  dp1[0] = 1;
  vector<mint> dp2(m+1);
  for (int i=0;i<n;i++){
    vector<mint> nxt1(m+1);
    for (int j=0;j<=m;j++){
      int nw = abs(A[i] - j);
      nxt1[nw] += dp1[j];
      nxt1[j] += dp1[j];
    }
    vector<mint> nxt2(m+1);
    for (int j=0;j<=m;j++){
      int nw = abs(A[i] - j);
      if (A[i] >= j) {
        nxt2[nw] += dp2[j] + dp1[j]*nw;
      } else {
        nxt2[nw] += dp2[j];
      }
      nxt2[j] += dp2[j];
    }
    dp1 = nxt1;
    dp2 = nxt2;
  }
  mint ans = 0;
  for (int i=0;i<=m;i++){
    ans += dp2[i];
  }
  cout << ans << "\n";
}

#if !defined(ONLINE_JUDGE)
#include "lib/stress.h"
void brute() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  sort(rbegin(A),rend(A));
  ll sum = 0;
  for (int msk=0;msk<(1<<n);msk++){
    vector<int> B;
    for (int i=0;i<n;i++){
      if (msk >> i & 1) {
        B.push_back(A[i]);
      }
    }
    int ans = 0;
    int last = 0;
    for (int i=(int)B.size()-1;i>=0;i--){
      while (B[i] && last < i) {
        B[i]--;
        B[last]--;
        ans++;
        if (B[last]==0) last++;
      }
      ans += B[i];
    }
    sum += ans;
  }
  cout << sum << "\n";
}

void gen_testcase(int t) {
  int n = 4;
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    cout << rnd(1, 3) << ' ';
  }
  cout << '\n';
}
#endif

signed main() {
#if !defined(ONLINE_JUDGE) && defined(STRESS)
  run_stress(100, false);
#else
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#endif
}

