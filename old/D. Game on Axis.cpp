#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  vector<int> nxt(n + 1);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (i + a < 0 || i + a >= n) {
      nxt[i] = n;
      adj[n].push_back(i);
    } else {
      nxt[i] = i + a;
      adj[i + a].push_back(i);
    }
  }
  vector<int> cnt(n + 1);
  auto dfs = [&](auto &&self, int u, int p) -> int {
    if (u != n) {
      cnt[u] = 1;
    }
    for (int v : adj[u]) {
      if (v == p) {
        continue;
      }
      cnt[u] += self(self, v, u);
    }
    return cnt[u];
  };
  dfs(dfs, n, -1);
  int ccnt = n - cnt[n];
  ll ans = 0;
  vector<int> vis(n);
  int cur = 0;
  while (!vis[cur]) {
    if (cnt[0] == 0) {
      ans += n + 1;
      ans += cnt[n];
    } else {
      ans -= cnt[cur];
      ans -= (n - cnt[n]);
    }
    vis[cur] = 1;
    cur = nxt[cur];
    if (cur == n)
      break;
  }
  if (cnt[0] != 0) {
    ans += (ll)n * (2 * n + 1);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
