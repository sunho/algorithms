#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct fenwick_tree_2d {
  int n, m;
  vector<vector<ll>> bits;
  fenwick_tree_2d(int n, int m) : n(n), m(m), bits(n+1, vector<ll>(m+1)) {}
  void update(int i, int j, int delta) { 
    for (++i; i <= n; i += i&(-i))
      for (int jj=j+1; jj <= m; jj += jj&(-jj))
        bits[i][jj] += delta;
  }
  ll query(int i, int j) {
    ll res = 0;
    for (++i; i > 0; i -= i&(-i))
      for (int jj=j+1; jj > 0; jj -= jj&(-jj))
        res += bits[i][jj];
    return res;
  }
  ll query(int i1, int j1, int i2, int j2) { 
    return query(i2, j2) + query(i1-1, j1-1) - query(i1-1,j2) - query(i2,j1-1); 
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n,q;
  cin >> n >> q;
  vector M(n, vector(n, 0));
  fenwick_tree_2d ft(n,n);
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      char c;
      cin >> c;
      M[i][j] = c == '*';
      ft.update(i,j,M[i][j]);
    }
  }
  while (q--){
    int t;
    cin >> t;
    if (t == 1) {
      int i, j;
      cin >> i >> j;
      --i,--j;
      if (M[i][j]) {
        ft.update(i,j,-1);
      } else {
        ft.update(i,j,1);
      }
      M[i][j] ^= 1;
    } else {
      int i1,j1,i2,j2;
      cin >> i1 >> j1 >> i2 >> j2;
      --i1,--j1,--i2,--j2;
      cout << ft.query(i1,j1,i2,j2) << "\n";
    }
  }
  
}


