#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fenwick Tree for summation
struct FenwickTree {
  int n;
  vector<ll> bits;
  FenwickTree(int n) : n(n), bits(n+1) {}
  void update(int v, int delta) {
    for (++v; v <= n; v += v&(-v)) 
      bits[v] += delta;
  }
  ll query(int r) {
    ll res = 0;
    for (++r; r > 0; r -= r&(-r))
      res += bits[r];
    return res;
  }
  ll query(int l, int r) {
    return query(r) - query(l-1);
  }
};

int main() {
  int n,q;
  cin >> n >> q;
  vector<int> A(n);
  FenwickTree ft(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  vector adj(n, vector<int>());
  for(int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> prd(n), tin(n), tout(n);
  int timer = 0;
  auto dfs = [&](auto self, int u, int p) -> void {
    prd[u] = p;
    tin[u] = timer++;
    for (int v : adj[u]) {
      if (v == p) continue;
      self(self, v,u);
    }
    tout[u] = timer-1;
  };
  dfs(dfs,0,0);

  for (int i=0;i<n;i++){
    ft.update(tin[i], A[i]);
  }

  while(q--){
    int t;
    cin >> t;
    if (t == 1){
      int v,s;
      cin >> v >> s;
      --v;
      ft.update(tin[v], s-A[v]);
      A[v] = s;
    } else {
      int v;
      cin >> v;
      v--;
      cout << ft.query(tin[v], tout[v]) << "\n";
    }
  }
}
