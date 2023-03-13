#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind {
  int n;
  vector<int> p;
  vector<int> sz;
  UnionFind(int n) : n(n), p(n), sz(n, 1) {
    iota(begin(p),end(p), 0);
  }
  
  int find_p(int x) {
    if (p[x] == x)
      return x;
    return p[x] = find_p(p[x]);
  }

  bool unite(int x, int y) {
    int u = find_p(x);
    int v = find_p(y);
    if (u == v) return false;
    if (sz[u] > sz[v]) {
      swap(u,v);
    }
    p[v] = u;
    sz[u] += sz[v];
    return true;
  }
};

void solve() {
  int n,m;
  cin >> n >> m;
  UnionFind uf(n);
  for (int i=0;i<m;i++) {
    int a,b;
    cin >> a >> b;
    --a,--b;
    uf.unite(a, b);
  }
  vector<int> cities(begin(uf.ssc), end(uf.ssc));
  cout << cities.size() - 1 << "\n";
  for (int i=0;i<cities.size()-1;i++){
    cout << cities[i]+1 << " " << cities[i+1] + 1 << "\n";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
