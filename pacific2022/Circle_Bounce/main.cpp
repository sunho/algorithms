#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1000000007; // 998244353
struct mint {
  int x;
  mint(int x = 0) : x(norm(x)) { }
  mint(ll x) : x(norm(x%MOD)) { }
  int norm(int x) const { if (x < 0) { x += MOD; } if (x >= MOD) { x -= MOD; } return x; }
  mint operator-() const { return mint(0)-*this; }
  mint operator+(mint o) const { return norm(x + o.x); }
  mint operator-(mint o) const { return norm(x - o.x); }
  mint operator*(mint o) const { return ll(x) * o.x; }
  mint &operator+=(mint o) { return *this = *this + o; }
  mint &operator-=(mint o) { return *this = *this - o; }
  mint &operator*=(mint o) { return *this = *this * o; }
  mint inv() const { return pow(MOD - 2); }
  mint pow(ll x) const {
    mint a = *this;
    mint b = 1;
    for (; x; x >>= 1) {
      if (x & 1)
        b *= a;
      a *= a;
    }
    return b;
  }
};

using Mat = array<array<mint, 2>, 2>;
Mat matmul(const Mat& A, const Mat& B) {
  Mat res{};
  for (int k=0;k<2;k++){
    for (int i=0;i<2;i++){
      for (int j=0;j<2;j++){
        res[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int a,b;
  ll n;
  cin >> a >> b >> n;
  ++n;
  mint x = b, y = a;
  mint x2 = mint(-1) + x*x*2*(x*x+y*y).inv();
  mint y2 = x*y*2*(x*x+y*y).inv();
  array<array<mint, 2>, 2> A = {{{1,0},{0,1}}};
  array<array<mint, 2>, 2> B = {{{-x2,-y2},{y2,-x2}}};
  while (n) {
    if (n&1) A = matmul(A,B); 
    n /= 2;
    B = matmul(B,B);
  }
  cout << (-A[0][0]).x << "\n";
}
