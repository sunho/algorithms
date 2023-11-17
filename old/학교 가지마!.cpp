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
  vector<vector<char>> M(n, vector<char>(m));
  pair<int,int> s,t;
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin >> M[i][j];
      if (M[i][j] == 'K') s={i,j};
      if (M[i][j] == 'H') t={i,j};
    }
  }
  Dinic flow(n*m*2);
  auto ti = [&](int i, int j) {
    return i*m + j;
  };
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      pair<int,int> cands[] = {{i+1,j},{i-1,j},{i,j+1},{i,j-1}};
      for (auto [x,y] : cands) {
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        flow.addEdge(ti(i,j)+n*m, ti(x,y), inf);
      }
    }
  }

  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++) {
      if (M[i][j] == '.') {
        flow.addEdge(ti(i,j), ti(i,j)+n*m, 1);
      } else if (M[i][j] == '#') {

      } else {
        flow.addEdge(ti(i,j), ti(i,j)+n*m, inf);
      }
    }
  }
  ll ans = flow.calc(ti(s.first, s.second), ti(t.first, t.second));
  if (ans == inf) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
  }
}
