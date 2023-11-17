#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct dinic {
	struct edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0ll); } // if you need flows
	};
	vector<int> lvl, ptr, q;
	vector<vector<edge>> adj;
	dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addedge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, (int)adj[b].size(), c, c});
		adj[b].push_back({a, (int)adj[a].size() - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < adj[v].size(); i++) {
			edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		for (int l=0;l<31;l++) do {
			lvl = ptr = vector<int>(q.size());
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - l))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, llong_max)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftofmincut(int a) { return lvl[a] != 0; }
};

int main() {
  const ll inf = 1e18;
  int n, m;
  cin >> n >> m;
  Dinic flow(2*n);
  for (int i=0;i<m;i++){ 
    int u,v;
    cin >> u >> v;
    --u,--v;
    flow.addEdge(u+n,v,inf);
    flow.addEdge(v+n,u,inf);
  }
  vector<int> B(n);
  for (int i=0;i<n;i++) {
    cin >> B[i];
    if (i == 0 || i == n-1)
      flow.addEdge(i,i+n,inf);
    else
      flow.addEdge(i,i+n,B[i]);
  }
  flow.calc(0, 2*n-1);
  vector<int> vis(2*n);
  auto dfs = [&](auto&& self, int u) -> void {
    if (vis[u]) return;
    vis[u] = true;
    for (auto e : flow.adj[u]) {
      if (e.c) {
        self(self,e.to);
      }
    }
  };
  dfs(dfs, 0);
  ll sum = 0;
  vector<int> ans;
  for (int i=1;i<n-1;i++){
    if (vis[i] && !vis[i+n]) {
      ans.push_back(i);
      sum += B[i];
    }
  }
  cout << sum << "\n";
  cout << ans.size() << "\n";
  for (int a : ans) {
    cout << a + 1 << " ";
  }
}
