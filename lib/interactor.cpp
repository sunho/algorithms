#ifndef ONLINE_JUDGE
struct Game {
  int n;
  Game(int n) : n(n) {}
  int query(int l, int r) { return 0; }
  bool answer(int n) { return true; }
};
#else
struct Game {
  int n;
  Game(int n) : n(n) {}
  int query(int l, int r) {
    cout << "? " << l + 1 < " " << r + 1 << endl;
    int res;
    cin >> res;
    return res;
  }
  bool answer(int n) {
    cout << "! " << n << endl;
    int res;
    cin >> res;
    return res;
  }
};
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifndef ONLINE_JUDGE
struct Game {
  int n;
  vector<vector<int>> adj;
  vector<int> p;
  vector<int> inv;
  Game(int n) : n(n), adj(n), p(n) {
    iota(begin(p), end(p), 0);
    shuffle(begin(p), end(p), rng);
  }
  int query(int l, int r) {
    l = p[l];
    r = p[r];
    queue<int> q;
    vector<int> dist(n, -1);
    dist[l] = 0;
    q.push(l);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (dist[v] == -1) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
    return dist[r];
  }
  void add(int x) {
    x -= 2;
    for (int i = 0; i < n; i++) {
      if (0 <= x - i && x - i < n) {
        adj[x - i].push_back(i);
        adj[i].push_back(x - i);
      }
    }
  }
  bool answer(vector<int> cand1, vector<int> cand2) {
    return cand1 == p || cand2 == p;
  }
};
#else
struct Game {
  int n;
  Game(int n) : n(n) {}
  int query(int l, int r) {
    cout << "? " << l + 1 << " " << r + 1 << endl;
    int res;
    cin >> res;
    assert(res != -1);
    return res;
  }
  void add(int x) {
    cout << "+ " << x << endl;
    int res;
    cin >> res;
  }
  bool answer(vector<int> cand1, vector<int> cand2) {
    cout << "! ";
    for (int a : cand1) {
      cout << a + 1 << " ";
    }
    for (int a : cand2) {
      cout << a + 1 << " ";
    }
    int res;
    cin >> res;
    return res == 1;
  }
};
#endif
