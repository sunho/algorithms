#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18;

#define dbg(x) "(" << #x <<": " << (x) << ") "
template<typename Ostream, typename Cont>
enable_if_t<is_same_v<Ostream,ostream>, Ostream&> 
operator<<(Ostream& os, const Cont& v){
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}
template<typename ...Ts>
ostream& operator<<(ostream& os, const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}

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
    fill(begin(res.data), end(res.data), -1);
    for (int t = 0; t < m; ++t) 
      for (int i = 0; i < n; ++i) 
        for (int j = 0; j < rhs.m; ++j) {
          if ((*this)[i][t] != -1 && rhs[t][j] != -1) {
            ll nd = (*this)[i][t] + rhs[t][j];
            if (res[i][j] == -1)
              res[i][j] = nd;
            else
              res[i][j] = min(res[i][j], nd);
          }
        }
    return res;
  }
  int n,m;
  vector<T> data;
};

template<typename T>
matrix<T> pow(matrix<T> a, ll p) {
  auto res = a;
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
  matrix<ll> adj(n);
  fill(begin(adj.data), end(adj.data), -1);
  while(m--){
    int a,b,c;
    cin >> a >> b >> c;
    --a,--b;
    if (adj[a][b] == -1)
      adj[a][b]=c;
    else
      adj[a][b] = min(adj[a][b], (ll)c);
  }
  adj = pow(adj, k-1);
  cout << adj[0][n-1] << "\n";
}
