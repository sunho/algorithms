// Sometimes this is faster...
struct Dinic {
  struct Edge {
    int to, rev;
    ll c, oc;
    ll flow() { return max(oc - c, 0LL); } // if you need flows
  };
  vector<int> lvl, ptr;
  vector<vector<Edge>> adj;
  Dinic(int n) : lvl(n), ptr(n), adj(n) {}
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
    ll flow = 0;
    while (true) {
      queue<int> q;
      lvl.assign(lvl.size(), -1);
      q.push(s);
      lvl[s] = 0;
      while (!q.empty()) {
        int u = q.front(); 
        q.pop();
        for (auto& e : adj[u]) {
          if (e.c < 1)
            continue;
          if (lvl[e.to] != -1)
            continue;
          lvl[e.to] = lvl[u] + 1;
          q.push(e.to);
        }
      }
      if (lvl[t] == -1)
        break;
      ptr.assign(ptr.size(), 0);
      while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
    }
    return flow;
  }
  bool leftOfMinCut(int a) { return lvl[a] != 0; }
};
