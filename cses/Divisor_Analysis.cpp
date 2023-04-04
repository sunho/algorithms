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
  mint power(ll n) { mint res = 1; mint a = *this; while (n) { if (n % 2) res = res * a; a = a * a; n /= 2; } return res; }
  mint inv() { return power(P-2); }
  mint& operator*=(const mint& rhs) { x = norm(((ll)x * rhs.x)%P); return *this; }
  mint& operator+=(const mint& rhs) { x = norm(x + rhs.x); return *this; }
  mint& operator-=(const mint& rhs) { x = norm(x - rhs.x); return *this; }
  #define OP(OO, OOE) friend mint operator OO(mint lhs, mint rhs) { mint res = lhs; res OOE rhs; return res; }
  OP(*, *=)
  OP(+, +=)
  OP(-, -=)
};

int main() {
  int n;
  cin >> n;
  vector<pair<int,int>> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
  }

  mint cnt = 1;
  for (int i=0;i<n;i++){
    cnt *= A[i].second+1;
  }
  
  mint sum = 0;
  for (int i=0;i<n;i++){
    auto [r,m] = A[i];
    mint r_inv = mint(r-1).inv();
    mint S = (mint(r).power(m+1) - r)*r_inv;
    sum += sum*S;
    sum += S;
  }
  sum += 1;

  mint product = 1;
  ll cnt2 = 1;
  for (int i=0;i<n;i++){
    auto [r,m] = A[i];
    ll c = (ll)m*(m+1)/2;
    product = product.power(m+1);
    product *= mint(r).power(c).power(cnt2);
    cnt2 *= (m+1);
    cnt2 %= P-1; 
  }

  cout << cnt.val() << " " << sum.val() << " " << product.val() << "\n";
}
