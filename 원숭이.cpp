#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<set<int>> adj(n);
  for (int i=0;i<n;i++){
    int m;
    cin >> m;
    while (m--) {
      int j;
      cin >> j;
      --j;
      adj[i].insert(j);
      adj[j].insert(i);
    }
  }
  vector<int> color(n);
  priority_queue<pair<int,int>> pq;
  set<int> in;
  auto calc = [&](int u) {
    int cnt = 0;
    for (int v : adj[u]) {
      if (color[u] == color[v]) cnt++;
    }
    return cnt;
  };
  for (int i=0;i<n;i++){
    if (calc(i) >= 2) {
      pq.push({adj[i].size(), i});
      in.insert(i);
    }
  }
  while (!pq.empty()) {
    auto [sz, u] = pq.top();
    in.erase(u);
    pq.pop();
    if (calc(u) >= 2) {
      color[u] ^= 1;
      for (int v : adj[u]) {
        if (!in.count(v)){
          if (calc(v) >= 2) {
            in.insert(v);
            pq.push({calc(v),v});
          }
        }
      }
    }
  }
  bool ok = true;
  for (int i=0;i<n;i++){
    if (color[i] != color[0]) {
      ok = false;
    }
  }
  if (ok) {
    color[0] ^= 1;
  }
  vector<int> A,B;
  for (int i=0;i<n;i++){
    if (color[i]) {
      B.push_back(i);
    } else {
      A.push_back(i);
    }
  }
  cout << A.size() << " ";
  for (int a : A) {
    cout << a + 1 << " ";
  }
  cout << "\n";
  cout << B.size() << " ";
  for (int a : B) {
    cout << a + 1 << " ";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
