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
mint& operator-=(mint& a, mint b) { if ((a.v -= b.v) < 0) a.v += MOD; return a; }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint operator*(mint a, mint b) { return mint((ll) a.v * b.v); }
mint& operator*=(mint& a, mint b) { return a = a * b; }
mint pow(mint a, ll p) { return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1); }
mint inv(mint a) { return pow(a, MOD - 2); }

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
 mat<mint, 7> ts{};
 for (int i=0;i<6;i++){
  ts[i][i+1] = 1;
  ts[6][i+1] = 1;
 }
 array<mint, 7> state{1,1,2,4,8,16,32};
 ll n;
 cin >> n;
 auto res = pow(ts, n) * state;
 cout << res[0].val() << "\n";
}
