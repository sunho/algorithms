#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Modular Integer
// does arithematics (mod P) automatically
int P = 1000000007; // 1000000007
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
  int n, x;
  cin >> n >> x;
  vector dp(x+1, mint(0));
  vector A(n, 0);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  dp[0] = 1;
  for (int i=0;i<=x;i++){
    for (int j=0;j<n;j++){
      if (i+A[j] <= x) {
        dp[i+A[j]] += dp[i];
      }
    }
  }
  cout << dp[x].val() << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
