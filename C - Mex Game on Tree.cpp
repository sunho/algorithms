#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> adj(n);
  vector<int> p(n);
  for (int i=1;i<n;i++){
    cin >> p[i];
    p[i]--;
    adj[p[i]].push_back(i);
  }
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  bool win = false;
  auto dfs = [&](auto&& self, int u) -> pair<set<int>,int> {
    set<int> cur;
    int z2 = A[u] == -1 ? 1 : 0;
    if (A[u] != -1) {
      cur.insert(A[u]);
    }
    for (int v : adj[u]) {
      auto [s, z] = self(self, v);
      z2 += z;
      if (cur.size() < s.size()) {
        swap(cur,s);
      }
      for (int x : s) {
        cur.insert(x);
      }
    }
    if (!cur.count(k)) {
      int cnt = 0;
      for (int i=0;i<k;i++){
        cnt += cur.count(i);
      }
      if (z2 == 1 && cnt == k-1) {
        win = true;
      } else if (z2 <= 1 && cnt == k) {
        win = true;
      }
    }
    return {cur, z2};
  };
  dfs(dfs, 0);
  if (win) {
    cout << "Alice" << "\n";
  } else {
    cout << "Bob" << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
