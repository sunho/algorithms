struct LCA {
	int T = 0;
	vector<int> time, path, ret;
	sparse_table rmq;

	LCA(vector<vector<int>>& adj) : time(adj.size()), 
    rmq((dfs(adj,0,-1), ret)) {
  }
	void dfs(vector<vector<int>>& adj, int u, int p) {
		time[u] = T++;
		for (int v : adj[u]) if (v != p) {
			path.push_back(u), ret.push_back(time[u]);
			dfs(adj, v, u);
		}
	}
	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b-1)];
	}
	//dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};
