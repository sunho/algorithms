#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vector<int> lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, (int)adj[b].size(), c, c});
		adj[b].push_back({a, (int)adj[a].size() - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < adj[v].size(); i++) {
			Edge& e = adj[v][i];
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
		for (int L=0;L<31;L++) do {
			lvl = ptr = vector<int>(q.size());
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int main() {
  const ll inf = 1e18;
  int n, m;
  cin >> n >> m;
  int s,t;
  cin >> s >> t;
  --s,--t;
  Dinic flow(2*n);
  vector<int> B(n);
  for (int i=0;i<n;i++) {
    cin >> B[i];
    flow.addEdge(i,i+n,B[i]);
  }
  for (int i=0;i<m;i++){ 
    int u,v;
    cin >> u >> v;
    --u,--v;
    flow.addEdge(u+n,v,inf);
    flow.addEdge(v+n,u,inf);
  }
  flow.calc(s, t+n);
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
  dfs(dfs, s);
  vector<int> ans;
  for (int i=0;i<n;i++){
    if (vis[i] && !vis[i+n]) {
      ans.push_back(i);
    }
  }
  for (int a : ans) {
    cout << a + 1 << " ";
  }
}
