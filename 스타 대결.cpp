#include <bits/stdc++.h>
#include <numeric>

using namespace std;
using ll = long long;

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
    if (v == t || !f)
      return f;
    for (int &i = ptr[v]; i < adj[v].size(); i++) {
      Edge &e = adj[v][i];
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
        for (auto &e : adj[u]) {
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
      while (ll p = dfs(s, t, LLONG_MAX))
        flow += p;
    }
    return flow;
  }
  bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  vector<int> B(m);
  for (int i = 0; i < m; i++) {
    cin >> B[i];
  }
  int sum = accumulate(begin(A), end(A), 0);
  if (accumulate(begin(A), end(A), 0) != accumulate(begin(B), end(B), 0)) {
    cout << -1 << "\n";
    return;
  }

  int s = n + m;
  int t = n + m + 1;

  Dinic ans(1);
  Dinic dinic(1);
  vector<vector<int>> banned(n, vector<int>(m));

  auto work = [&]() {
    dinic = Dinic(n + m + 2);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!banned[i][j]) {
          dinic.addEdge(i, j + n, 1);
        } else {
          dinic.addEdge(i, j + n, 0);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      dinic.addEdge(s, i, A[i]);
    }
    for (int i = 0; i < m; i++) {
      dinic.addEdge(i + n, t, B[i]);
    }
    return dinic.calc(s, t) == sum;
  };

  if (!work()) {
    cout << -1 << "\n";
    return;
  }
  ans = dinic;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      banned[i][j] = 1;
      if (work()) {
        ans = dinic;
      } else {
        banned[i][j] = 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ans.adj[i][j].flow()) {
        cout << "1";
      } else {
        cout << "0";
      }
    }
    cout << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
