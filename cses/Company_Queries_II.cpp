#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

void solve() {
  int n,q;
  cin >> n >> q;
  vector<int> prd(n);
  vector adj(n, vector<int>());
  for (int i=1;i<n;i++){
    cin >> prd[i];
    prd[i]--;
    adj[prd[i]].push_back(i);
  }
  auto up = treeJump(prd);
  vector<int> depth(n);
  auto dfs = [&](auto self, int u, int p, int level) -> void {
    depth[u] = level;
    for (int v : adj[u]) if (v != p) {
      self(self, v, u, level+1);
    }
  };
  dfs(dfs,0,-1,0);

  while(q--){
    int u,v;
    cin >> u >> v;
    --u,--v;
    cout << lca(up, depth, u,v) + 1 << "\n";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}



/*
  int time = 0;
  vector<int> tin(n);
  vector<int> tout(n);
  auto dfs = [&](auto self, int u, int p) -> void {
    tin[u] = time++;
    for (int v : adj[u]) {
      if (v == p) continue;
      self(self, v, u);
    }
    tout[u] = time++;
  };
  dfs(dfs, 0, -1);
  auto is_ancestor = [&](int u, int v) -> bool {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
  };

  while(q--){
    int u,v;
    cin >> u >> v;
    --u,--v;
    if (is_ancestor(u, v)){
      cout << u + 1 << "\n";
      continue;
    }
    for (int i=l-1;i>=0;i--){
      if (!is_ancestor(up[u][i], v))
        u = up[u][i];
    }
    cout << up[u][0] + 1 << "\n";
  }
*/