#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int P = 1000000007; // 998244353
struct mint {
  int x;
  int norm(int x) const { if (x < 0) { x += P; } if (x >= P) { x -= P; } return x; }
  mint(int x = 0) : x(norm(x)) {}
  mint(ll x) : x(norm(x % P)) {}
  int val() const { return x; }
  mint power(int n) { mint res = 1; mint a = *this; while (n) { if (n % 2) res = res * a; a = a * a; n /= 2; } return res; }
  mint inv() { return power(P-2); }
  mint& operator*=(const mint& rhs) { x = norm(((ll)x * rhs.x)%P); return *this; }
  mint& operator+=(const mint& rhs) { x = norm(x + rhs.x); return *this; }
  mint& operator-=(const mint& rhs) { x = norm(x - rhs.x); return *this; }
  #define OP(OO, OOE) friend mint operator OO(mint lhs, mint rhs) { mint res = lhs; res OOE rhs; return res; }
  OP(*, *=)
  OP(+, +=)
  OP(-, -=)
};

void solve() {
  int n,m;
  cin >> n >> m;
  vector dp(m, mint(0));
  int a;
  cin >> a;
  if (a != 0) {
    dp[a-1] = 1;
  } else {
    dp.assign(m, 1);
  }
  for (int i=0;i<n-1;i++) {
    vector next(m, mint(0));
    int a;
    cin >> a;
    --a;
    if (a != -1) {
      if (a-1 >= 0)
        next[a] += dp[a-1];
      if (a+1 < m)
        next[a] += dp[a+1];
      next[a] += dp[a];
      dp = move(next);
      continue;
    }
    for (int j=0;j<m;j++){
      if (j-1 >= 0)
        next[j] += dp[j-1];
      if (j+1 < m)
        next[j] += dp[j+1];
      next[j] += dp[j];
    }
    dp = move(next);
  }
  mint ans = 0;
  for (auto x : dp) {
    ans += x;
  }
  cout << ans.val() << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
