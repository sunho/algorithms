const ll inf = 1e18;
vector<ll> d(n, inf);
vector<int> cnt(n, 0);
vector<bool> inqueue(n, false);
vector<bool> negcyc(n);
queue<int> q;

d[0] = 0;
q.push(0);
inqueue[0] = true;
cnt[0]++;
while (!q.empty()) {
  int u = q.front();
  q.pop();
  inqueue[u] = false;

  for (auto [v, w] : g[u]) {
    if (negcyc[u]) {
      if (!negcyc[v] && !inqueue[v]) {
        inqueue[v] = true;
        q.push(v);
      }
      negcyc[v] = true;
    } else if (!negcyc[v] && d[u] + (ll)w < d[v]) {
      d[v] = d[u] + (ll)w;
      if (!inqueue[v]) {
        cnt[v]++;
        if (cnt[v] <= n) {
          inqueue[v] = true;
          q.push(v);
        } else {
          inqueue[v] = true;
          negcyc[v] = true;
          q.push(v);
        }
      }
    } 
  }
}