#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct fenwick_tree_2d {
  int n, m;
  vector<vector<ll>> bits;
  fenwick_tree_2d(int n, int m) : n(n), m(m), bits(n + 1, vector<ll>(m + 1)) {}
  void update(int x, int y, int delta) {
    for (int i=x+1;i<=n;i+=i&-i)
      for (int j=y+1;j<=m;j+=j&-j)
        bits[i][j] += delta;
  }
  ll query(int x, int y) {
    ll res = 0;
    for (int i=x+1;i>0;i-=i&-i)
      for (int j=y+1;j>0;j-=j&-j)
        res += bits[i][j];
    return res;
  }
  ll query(int i1, int j1, int i2, int j2) {
    return query(i2, j2) + query(i1-1, j1-1) - query(i1-1, j2) - query(i2, j1-1);
  }
};

void solve() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> A(n, vector<int>(m));
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin >> A[i][j];
    }
  }
  int ok = 0, ng = min(n,m)+1;
  auto check = [&](int w) {
    fenwick_tree_2d ft(n, m);
    for (int i=0;i<n;i++){
      for (int j=0;j<m;j++){
        if (A[i][j] < w) {
          ft.update(i,j,1);
        }
      }
    }
    for (int i=0;i<n-w+1;i++){
      for (int j=0;j<m-w+1;j++){
        if (!ft.query(i,j,i+w-1,j+w-1)) {
          return true;
        }
      }
    }
    return false;
  };
  while (ng-ok>1) {
    int mid = (ok+ng)/2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << "\n";
}


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
