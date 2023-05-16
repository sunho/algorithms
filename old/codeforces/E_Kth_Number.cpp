#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353; // 998244353
struct mint {
  int x;
  mint(int x = 0) : x(norm(x)) { }
  mint(ll x) : x(norm(x%MOD)) { }
  int norm(int x) const { if (x < 0) { x += MOD; } if (x >= MOD) { x -= MOD; } return x; }
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

mint geo(mint r, int k) {
  if (k == 0) return 0;
  if (r.x == 1) {
    return r*k;
  }
  return (mint(1)-r.pow(k))*((mint(1)-r).inv());
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,m,k;
  cin >> n >> m >> k;
  --k;
  vector<int> A(n);
  int zero = 0;
  const int inf = 1e9;
  for (int i=0;i<n;i++){
    cin >> A[i];
    if (A[i] == 0) {
      zero++;
      A[i] = inf;
    }
  }
  sort(A.begin(), A.end());
  A.resize(n-zero);
  n = A.size();
  vector<vector<mint>> binom(zero+1, vector<mint>(zero+1));
  binom[0][0] = 1;
  for (int i=1;i<=zero;i++) {
    binom[i][0] = 1;
    for (int j=1;j<=i;j++){
      binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
    }
  }
  mint ans = 0;
  for (int a=1;a<=m;a++){
    int less = lower_bound(begin(A),end(A), a) - A.begin();
    mint res = 0;
    for (int s=0;s<=min(k-less,zero);s++){
      mint x = binom[zero][s] * mint(a-1).pow(s) * mint(m-a+1).pow(zero-s);
      res += x;
    }
    ans += res * mint(m).inv().pow(zero);
  }
  cout << ans.x << "\n";
}
