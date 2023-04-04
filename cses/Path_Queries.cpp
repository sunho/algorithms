#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fenwick Tree for summation
struct fenwick_tree {
  int n;
  vector<ll> bits;
  fenwick_tree(int n) : n(n), bits(n+1) {}

  // add delta to node v
  void update(int v, int delta) {
    for (++v; v <= n; v += v&(-v)) 
      bits[v] += delta;
  }

  // get prefix sum of range [0,r]
  ll query(int r) {
    ll res = 0;
    for (++r; r > 0; r -= r&(-r))
      res += bits[r];
    return res;
  }
};

int main() {
  int n,q;
  cin >> n >> q;
  int timer = 0;
  vector<int> tin(n);
  vector<int> tout(n);
  vector<int> A(n);
  for (int i=0;i<n;i++)
    cin >> A[i];
  vector adj(n, vector<int>());
  for (int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    --a,--b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  fenwick_tree ft(2*n);
  auto dfs = [&](auto self, int u, int p) -> void {
    tin[u] = timer++;
    for (int v : adj[u]) {
      if (v == p)
        continue;
      self(self, v, u);
    }
    tout[u] = timer++;
  };
  dfs(dfs, 0, -1);
  for (int i=0;i<n;i++){
    ft.update(tin[i], A[i]);
    ft.update(tout[i], -A[i]);
  }
  while (q--){
    int t;
    cin >> t;
    if (t == 1) {
      int i, a;
      cin >> i >> a;
      --i;
      ft.update(tin[i], -A[i]+a);
      ft.update(tout[i], A[i]-a);
      A[i] = a;
    } else {
      int i;
      cin >> i;
      --i;
      cout << ft.query(tin[i]) << "\n";
    }
  }
}