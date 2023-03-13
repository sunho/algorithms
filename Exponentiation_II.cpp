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
  mint power(ll n) { mint res = 1; mint a = *this; while (n) { if (n % 2) res = res * a; a = a * a; n /= 2; } return res; }
  mint inv() { return power(P-2); }
  #define OP(OO, OOE) mint& operator OOE(const mint& rhs) { x = norm((ll(x) OO rhs.x) % P); return *this; }\
  friend mint operator OO(mint lhs, mint rhs) { mint res = lhs; res OOE rhs; return res; }
  OP(*, *=)
  OP(+, +=)
  OP(-, -=)
};

void solve() {
  int a,b,c;
  cin >> a >> b >> c;
  P--;
  int k = mint(b).power(c).val();
  P++;
  cout << mint(a).power(k).val() << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
