#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int P = 1000000007; // 1000000007
struct mint {
  int x;
  int norm(int x) const { if (x < 0) { x += P; } if (x >= P) { x -= P; } return x; }
  mint(int x = 0) : x(norm(x)) {}
  mint(ll x) : x(norm(x % P)) {}
  int val() const { return x; }
  mint power(int n) { mint res = 1; mint a = *this; while (n) { if (n % 2) res = res * a; a = a * a; n /= 2; } return res; }
  mint inv() { return power(P-2); }
  #define OP(OO, OOE) mint& operator OOE(const mint& rhs) { x = norm((ll(x) OO rhs.x) % P); return *this; }\
  friend mint operator OO(mint lhs, mint rhs) { mint res = lhs; res OOE rhs; return res; }
  OP(*, *=)
  OP(+, +=)
  OP(-, -=)
};

void solve() {
  ll n;
  cin >> n;

  mint ans = 0;
  mint inv2 = mint(2).inv();
  for (ll d = 1; d*d <= n; d++) {
    mint m = n / d;
    ans += (m-d+1)*d;
    ans += m*(m+1)*inv2 - (d-1)*d*inv2;
    if (d*d <= n) {
      ans -= d;
    }
  }
  cout << ans.val() << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
