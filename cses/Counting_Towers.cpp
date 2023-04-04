#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;

// Modular Integer
// does arithematics (mod P) automatically
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
  int t;
  cin >> t; 
  int N = 1e6;
  vector dp(N+1, array<mint,2>{});
  dp[0][0] = 1;
  dp[0][1] = 1;
  for (int i=0;i<N-1;i++){
    dp[i+1][0] += dp[i][1];
    dp[i+1][0] += 2*dp[i][0];
    dp[i+1][1] += dp[i][0];
    dp[i+1][1] += 4*dp[i][1];
  } 
  while (t--) {
    int n;
    cin >> n;
    
    cout << (dp[n-1][0] + dp[n-1][1]).val() << "\n";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
