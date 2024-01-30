#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<int>> mnJump(vector<vector<int>>& up, vector<int>& A){
	int d = ceil(log2(A.size()));
	vector<vector<int>> res(d, A);
	for(int i=1;i<d;i++) for(int j=0;j<A.size();j++)
		res[i][j] = max(res[i-1][j], res[i-1][up[i-1][j]]);
	return res;
}

vector<vector<int>> treeJump(vector<int>& P){
	int d = ceil(log2(P.size()));
	vector<vector<int>> up(d, P);
	for(int i=1;i<d;i++) for(int j=0;j<P.size();j++)
		up[i][j] = up[i-1][up[i-1][j]];
	return up;
}

int jmp(vector<vector<int>>& up, int node, int steps){
	for(int i=0;i<up.size();i++)
		if(steps&(1<<i)) node = up[i][node];
	return node;
}

int lca(vector<vector<int>>& up, vector<int>& depth, int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	a = jmp(up, a, depth[a] - depth[b]);
	if (a == b) return a;
	for (int i = up.size()-1;i>=0;i--) {
		int c = up[i][a], d = up[i][b];
		if (c != d) a = c, b = d;
	}
	return up[0][a];
}

// Union Find using disjoint subset union
struct union_find {
  int n;
  vector<int> p;
  vector<int> sz;
  union_find(int n) : n(n), p(n), sz(n, 1) {
    iota(begin(p),end(p), 0);
  }
  int leader(int x) {
    if (p[x] == x)
      return x;
    return p[x] = leader(p[x]);
  }
  void unite(int x, int y) {
    int l = leader(x), s = leader(y);
    if (l == s) return;
    if (sz[s] > sz[l]) swap(s,l);
    p[s] = l, sz[l] += sz[s];
  }
};

void solve() {
  int n,m;
  cin >> n >> m;
  vector<tuple<int,int,int>> edges;
  for (int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    --u,--v;
    edges.push_back({w,u,v});
  }
  sort(begin(edges),end(edges));
  vector<vector<pair<int,int>>> adj(n);
  union_find uf(n);
  map<int,int> sz;
  for (auto [w,u,v] : edges) {
    if (uf.leader(u) != uf.leader(v)) {
      uf.unite(u,v);
      sz[w] = uf.sz[uf.leader(u)];
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }
  }
  vector<int> depth(n);
  const int inf = 1e9+3;
  vector<int> A(n,0);
  vector<int> P(n,-1);
  auto dfs = [&](auto&& self, int u, int p, int d) -> void {
    P[u] = p;
    depth[u] = d; 
    for (auto [v,w] : adj[u]) {
      if (p == v) continue;
      A[v] = w;
      self(self, v, u, d+1);
    }
  };
  for (int i=0;i<n;i++) {
    if (P[i] == -1) {
      dfs(dfs, i, i, 0);
    }
  }
  auto up = treeJump(P);
  auto mnUp = mnJump(up, A);
  auto jump = [&](int u, int k) {
    int res = -inf;
    for (int i=up.size()-1;i>=0;i--) {
      if ((k >> i) & 1) {
        res = max(res, mnUp[i][u]);
        u = up[i][u];
      }
    }
    return res;
  };
  int q;
  cin >> q;
  while (q--) {
    int u,v;
    cin >> u >> v;
    --u,--v;
    if (uf.leader(u) != uf.leader(v)) {
      cout << -1 << "\n";
    } else {
      int mn = 0;
      int l = lca(up, depth, u,v);
      if (l != u) {
        mn = max(mn, jump(u, depth[u]-depth[l]));
      }
      if (l != v) {
        mn = max(mn, jump(v, depth[v]-depth[l]));
      }
      cout << mn << " " << sz[mn] << "\n";
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
