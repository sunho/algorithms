#include <bits/stdc++.h>
#include <vector>

using namespace std;

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

vector<vector<int>> treeJump(vector<int>& P){
	int d = ceil(log2(P.size()));
	vector<vector<int>> up(d, P);
	for(int i=1;i<d;i++) for(int j=0;j<P.size();j++)
		up[i][j] = up[i-1][up[i-1][j]];
	return up;
}

vector<vector<int>> treeMaxs(vector<vector<int>>& up, vector<int>& A){
	int d = ceil(log2(A.size()));
	vector<vector<int>> res(d, A);
	for (int i=0;i<A.size();i++) {
		res[0][i] = max(A[i], A[up[0][i]]);
	}
	for(int i=1;i<d;i++) for(int j=0;j<A.size();j++)
		res[i][j] = max(res[i-1][j], res[i-1][up[i-1][j]]);
	return res;
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

int main() {
	int n,m,q;
	cin >> n >> m >> q;
	vector<vector<int>> M(n, vector<int>(m));
	vector<int> A(n*m);
	vector<vector<int>> idx(n, vector<int>(m));
	vector<pair<int,int>> inv(n*m);
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			idx[i][j] = i*m + j;
			inv[i*m+j] = {i,j};
		}
	}
	vector<tuple<int,int,int>> wl;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cin >> M[i][j];
			A[idx[i][j]] = M[i][j];
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			pair<int,int> pos[] = {{i-1,j},{i+1,j},{i,j-1},{i,j+1}};
			for (auto [x,y] : pos) {
				if (x < 0 || x>= n || y < 0 || y >= m) continue;
				wl.push_back({max(M[i][j], M[x][y]), idx[i][j], idx[x][y]});
			}
		}
	}
	sort(wl.begin(), wl.end());

	union_find uf(n*m);
	vector<vector<int>> adj(n*m);

	for (auto [w, id, id2] : wl) {
		if (uf.leader(id) != uf.leader(id2)) {
			uf.unite(id, id2);
			adj[id].push_back(id2);
			adj[id2].push_back(id);
		}
	}

	vector<int> P(n*m);
	vector<int> depth(n*m);
	auto dfs = [&](auto self, int u, int p, int level) -> void {
		depth[u] = level;
		P[u] = p;
		for (int v : adj[u]) {
			if (v == p) continue;
			self(self, v, u, level+1);
		}
	};
	dfs(dfs, 0, 0, 0);
	
	auto up = treeJump(P);
	auto maxes = treeMaxs(up, A);
	
	auto get_max = [&](int u, int steps) -> int {
		int res = A[u];
		for(int i=0;i<up.size();i++)
			if(steps&(1<<i)) {
				res=max(res,maxes[i][u]);
				u = up[i][u];
			}
		return res;
	};

	while (q--) {
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		--x1,--y1,--x2,--y2;
		int id1 = idx[x1][y1], id2 = idx[x2][y2];
		int lc = lca(up, depth, id1, id2);
		cout << max({A[lc], get_max(id1, depth[id1] - depth[lc]), get_max(id2, depth[id2] - depth[lc])}) << "\n";
	}
}
