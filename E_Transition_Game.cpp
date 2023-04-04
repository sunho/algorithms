#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
    A[i]--;
  }
  set<int> ban;
  vector<int> vis(n); 
  auto dfs = [&](auto self, int u) -> void {
    vis[u] = 2;
    int v = A[u];
    if (vis[v] == 2) {
      int cur = v;
      ban.insert(u);
      while (cur != u) {
        ban.insert(cur);
        cur = A[cur];
      }
    } else if (vis[v] == 0) {
      self(self, v);
    }
    vis[u] = 1;
  };
  for (int i=0;i<n;i++){
    dfs(dfs, i);
  }
  cout << ban.size() << "\n";
}
