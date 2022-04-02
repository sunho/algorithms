auto dfs = [&](pair<int,int> u, auto&& self) -> void {
	if (seen[u.x][u.y]) return;
	seen[u.x][u.y] = true;
	vector<pair<int,int>> dirs = { {u.x-1, u.y}, {u.x+1,u.y}, {u.x, u.y-1}, {u.x, u.y+1} };
	int al = getdegree(u);
	if (M[u.x][u.y] == '.') {
		M[u.x][u.y] = '+';
	}
	for(auto dir : dirs) if (isvalid(dir)) {
		if(getdegree(dir) <= 1) {
			self(dir,self);
		}
	}
};

auto dfs = [&](int u, int p, auto&& self) -> void {
	if (visited[u]) {
		return;
	}
	visited[u] = 1;
	for (auto x:g[u]) {
		if (x == p) continue;
		self(x, u, self);
	}
};