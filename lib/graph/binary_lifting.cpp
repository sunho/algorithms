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

vector<vector<int>> mnJump(vector<vector<int>>& up, vector<int>& A){
	int d = ceil(log2(A.size()));
	vector<vector<int>> res(d, A);
	for(int i=1;i<d;i++) for(int j=0;j<A.size();j++)
		res[i][j] = min(res[i-1][j], res[i-1][up[i-1][j]]);
	return res;
}

vector<vector<int>> mxJump(vector<vector<int>>& up, vector<int>& A){
	int d = ceil(log2(A.size()));
	vector<vector<int>> res(d, A);
	for(int i=1;i<d;i++) for(int j=0;j<A.size();j++)
		res[i][j] = max(res[i-1][j], res[i-1][up[i-1][j]]);
	return res;
}


