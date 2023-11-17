#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

struct fenwick_tree {
  int n;
  vector<ll> bits;
  fenwick_tree(int n) : n(n), bits(n+1) {}
  void update(int r, int delta) { 
    for (++r; r <= n; r += r&(-r)) bits[r] += delta;
  }
  ll query(int v) {
    ll res = 0;
    for (++v; v > 0; v -= v&(-v)) res += bits[v];
    return res;
  }
  void update(int l, int r, int delta) { 
		update(l, delta);
		update(r+1, -delta);
	}
};


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	vector<vector<int>> adj(n);
	for (int i=0;i<n;i++){
		int p;
		cin >> p;
		if (p != -1) {
			--p;
			adj[p].push_back(i);
			adj[i].push_back(p);
		}
	}

	vector<int> tin(n), tout(n);
	int timer = 0;
	auto dfs = [&](auto self, int u, int p) -> void {
		tin[u] = timer++;
		for (int v : adj[u]) {
			if (v == p) continue;
			self(self, v, u);
		}
		tout[u] = timer - 1;
	};
	dfs(dfs, 0, 0);

	fenwick_tree ft(n);

	while (q--) {
		int a;
		cin >> a;
		if (a == 1) {
			int u, k;
			cin >> u >> k;
			--u;
			ft.update(tin[u], tout[u], k);
		} else {
			int u;
			cin >> u;
			--u;
			cout << ft.query(tin[u]) << "\n";
		}
	}
}
