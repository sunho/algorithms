// khan's algorithm
// ====
queue<int> q;
for(int i = 0; i < n; i++) {
  if (deg[i] == 0) {
    q.push(i);
  }
}

vector<int> order;
int cnt = 0;
while (!q.empty()) {
  int u = q.front();
  q.pop();
  cnt++;
  order.push_back(u);
  for(auto v : g[u]) {
    if (--deg[v] == 0) {
      q.push(v);
    }
  }
}
if (cnt != n) cout << "cycle" << endl;

// ====
// input exmple
vector<vi> g(n);
vi deg(n);
for(int i = 0; i < m; i++) {
  int a,b;
  cin >> a >> b;
  a--,b--;
  g[b].push_back(a);
  deg[a]++;
}
// ====

