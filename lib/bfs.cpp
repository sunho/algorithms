vector<vector<int>> g;

queue<int> q;
vector<bool> used(n);
vector<int> d(n), p(n);

q.push(0);
used[0] = true;
p[0] = -1;
while (!q.empty()) {
  int v = q.front();
  q.pop();
  for (int u : g[v]) {
    if (!used[u]) {
      used[u] = true;
      q.push(u);
      d[u] = d[v] + 1;
      p[u] = v;
    }
  }
}