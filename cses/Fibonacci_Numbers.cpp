#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Modular Integer
// does arithmetics (mod P) automatically
int MOD = 1000000007; // 998244353
struct mint {
  int v=0; 
  int val() { return v; }
  mint() = default;
  mint(ll v) : v(v % MOD) { v += (v < 0) * MOD; }
};
mint& operator+=(mint& a, mint b) { if ((a.v += b.v) >= MOD) a.v -= MOD; return a; }
mint operator*(mint a, mint b) { return mint((ll) a.v * b.v); }

template <typename T,size_t N>
using mat = array<array<T,N>, N>;

template <typename T,size_t N>
mat<T,N> operator*(const mat<T,N>& lhs, const mat<T,N>& rhs) { 
  mat<T,N> res{};
  for (int t = 0; t < N; ++t) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        res[i][j] += lhs[i][t] * rhs[t][j];
      }
    }
  }
  return res;
}

template <typename T,size_t N>
array<T,N> operator*(const mat<T,N>& lhs, const array<T,N>& rhs) { 
  array<T,N> res{};
    for (int i = 0; i < N; ++i) {
      for (int t = 0; t < N; ++t) {
        res[i] += lhs[i][t] * rhs[t];
      }
  }
  return res;
}

template <typename T,size_t N>
mat<T,N> pow(mat<T,N> a, ll n) {
  mat<T,N> res{};
  for (int i=0;i<N;i++) res[i][i] = 1;
  while (n) {
    if (n & 1)
      res = res * a;
    a = a * a;
    n >>= 1;
  }
  return res;
}

int main() {
  mat<mint,3> ts = {{
    {0,1,0},
    {0,0,1},
    {0,1,1}
  }};

  ll n;
  cin >> n;
  auto res = pow(ts, n) * array<mint,3>{0,1,1};
  cout << res[0].val() << "\n";
}
