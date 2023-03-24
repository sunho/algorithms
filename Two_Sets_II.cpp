#include <bits/stdc++.h>
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
  int n;
  cin >> n;
  int N = n*(n+1)/2;
  if (N%2 != 0) {
    cout << 0 << "\n";
    return;
  }
  N/=2;
  vector<mint> dp(N+1);
  dp[0] = 1;
  for (int i=1;i<=n;i++){
    for (int j=N;j>=0;j--){
      if (j-i >= 0)
        dp[j] += dp[j-i];
    }
  }
  mint inv2 = mint(2).inv();
  cout << (dp[N]*inv2).val() << "\n"; 
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
