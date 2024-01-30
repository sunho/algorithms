#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
    A[i]--;
  }
  vector<int> cycle(n);
  vector<int> color(n);
  auto dfs = [&](auto&& self, int u) -> void {
    if (color[u] == 2) {
      int cur = A[u];
      while (cur != u) {
        cycle[cur] = true;
        cur = A[cur];
      }
      cycle[u] = true;
    } else if (color[u] == 0) {
      int v = A[u];
      color[u] = 2;
      self(self, v);
      color[u] = 1;
    }
  };
  for (int i=0;i<n;i++){
    if (!color[i]) {
      dfs(dfs, i);
    }
  }
  cout << n - accumulate(begin(cycle),end(cycle),0) << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
