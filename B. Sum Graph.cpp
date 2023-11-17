#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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

void solve() {
  int n;
  cin >> n;
  Game game(n);
  game.add(n);
  game.add(n + 1);
  vector<int> dist1(n);
  for (int i = 1; i < n; i++) {
    dist1[i] = game.query(0, i);
  }
  int mx = max_element(begin(dist1), end(dist1)) - begin(dist1);
  vector<int> dist2(n);
  for (int i = 0; i < n; i++) {
    if (i != mx) {
      dist2[i] = game.query(mx, i);
    }
  }
  auto B = dist2;
  sort(begin(B), end(B));
  vector<int> C(n);
  iota(begin(C), end(C), 0);
  assert(C == B);
  vector<int> cand1, cand2;
  for (int i = 0; i < n; i++) {
    if (dist2[i] % 2 == 0)
      cand1.push_back(n - dist2[i] / 2 - 1);
    else
      cand1.push_back((dist2[i] + 1) / 2 - 1);
  }
  for (int i = 0; i < n; i++) {
    dist2[i] = n - dist2[i] - 1;
  }
  for (int i = 0; i < n; i++) {
    if (dist2[i] % 2 == 0)
      cand2.push_back(n - dist2[i] / 2 - 1);
    else
      cand2.push_back((dist2[i] + 1) / 2 - 1);
  }
  assert(game.answer(cand1, cand2));
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
