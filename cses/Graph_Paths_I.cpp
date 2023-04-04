#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
struct matrix {
  matrix(int n, int m) : n(n), m(m), data(n*m) {}
  matrix(int n) : matrix(n,n) {}
  matrix(initializer_list<initializer_list<T>> l) : matrix(l.size(), m(l.begin()->size()))  {
    int i = 0; for (auto& row : l) copy(row.begin(), row.end(), &data[m * i++]);
  }
  static matrix ones(int n) { matrix res(n); for (int i=0;i<n;i++) res[i][i] = 1; return res; }
  T* operator[](int i) { return &data[m*i]; }
  const T* operator[](int i) const { return &data[m*i]; }
  matrix operator*(const matrix& rhs) {
    assert(m == rhs.n);
    matrix res(n, rhs.m);
    for (int t = 0; t < m; ++t) 
      for (int i = 0; i < n; ++i) 
        for (int j = 0; j < rhs.m; ++j) 
          res[i][j] += (*this)[i][t] * rhs[t][j];
    return res;
  }
  int n,m;
  vector<T> data;
};

// Modular Integer
// does arithmetics (mod P) automatically
const int MOD = 1000000007; // 998244353
struct mint {
  int v;
  mint() : v(0) {}
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
mint operator/(mint a, mint b) { return a * inv(b); }

template<typename T>
matrix<T> pow(matrix<T> a, ll p) {
  auto res = matrix<T>::ones(a.n);
  while (p) {
    if (p&1) res = res * a;
    a = a*a, p/=2;
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m, k;
  cin >> n >> m >> k;
  matrix<mint> adj(n);
  while(m--){
    int a,b;
    cin >> a >> b;
    --a,--b;
    adj[a][b]+=1;
  }
  adj = pow(adj, k);
  cout << adj[0][n-1].v << "\n";
}
