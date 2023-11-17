#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
    A[i]--;
  }
  if (any_of(begin(A),end(A),[&](int a) { return a >= n; })) {
    cout << -1 << "\n";
    return 0;
  }
  vector<vector<int>> child(n);
  vector<int> indeg(n);
  for (int i=0;i<n;i++){
    indeg[A[i]]++;
  }
  queue<int> qu;
  for (int i=0;i<n;i++){
    if (indeg[i] == 0) {
      qu.push(i);
    }
  }
  vector<int> state(n);
  vector<int> vis(n);
  while (!qu.empty()) {
    int u = qu.front();
    qu.pop();
    vis[u] = 1;
    if (vis[A[u]]) continue;
    state[A[u]] = 1;
    vis[A[u]] = 1;
    if (!--indeg[A[A[u]]]) {
      qu.push(A[A[u]]);
    }
  }
  for (int i=0;i<n;i++){
    if (!vis[i]) {
      int cnt = 1;
      int u = i;
      u = A[u];
      while (u != i) {
        vis[u] = true;
        if (cnt % 2 == 1) {
          state[u] = 1;
        }
        cnt ++;
        u = A[u];
      }
      if (cnt % 2 == 1) {
        cout << -1 << "\n";
        return 0;
      }
    }
  }

  vector<int> ans;
  for (int i=0;i<n;i++){
    if (!state[i]) {
      ans.push_back(A[i]);
    }
  }
  cout << ans.size() << "\n";
  for (int a : ans) {
    cout << a + 1 << " ";
  }
}
