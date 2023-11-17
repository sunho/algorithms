#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for (int i=0;i<n-1;i++){
		int u,v;
		cin >> u >> v;
		--u,--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (n <= 3) {
		cout << 0 << "\n";
		return 0;
	}
	ll triple = (ll)n*(n-1)*(n-2)/6;
	ll doub = (ll)n*(n-1)/2;
	vector<int> sz(n);
	vector<ll> dp(n);
	auto dfs = [&](auto self, int u, int p, int depth) -> void {
		sz[u] = 1;
		dp[0] += depth;
		for (auto v : g[u]) {
			if (v == p) continue;
			self(self, v, u, depth+1);
			sz[u] += sz[v];
		}
	};
	dfs(dfs, 0, -1, 0);
	ll dist_sum = 0;
	auto dfs2 = [&](auto self, int u, int p) -> void {
		if (p != -1)
			dp[u] = dp[p] + n - 2*sz[u];
		dist_sum += dp[u];
		for (auto v : g[u]) {
			if (v == p) continue;
			self(self, v, u);
		}
	};
	dfs2(dfs2, 0, -1);
	cout << triple - (dist_sum/2 - doub) << "\n";
}
