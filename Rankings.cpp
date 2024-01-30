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
  vector<int> rank(n);
  for (int i=0;i<n;i++){
    rank[A[i]] = i;
  }
  vector<int> deg(n);
  for (int i=0;i<n;i++){
    deg[A[i]] = i;
  }
  int m;
  cin >> m;
  for (int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    if (rank[u] > rank[v]) {
      swap(u,v);
    }
    deg[u]++;
    deg[v]--;
  }
  vector<int> deg2 = deg;
  sort(begin(deg2),end(deg2));
  vector<int> id(n);
  iota(begin(id),end(id),0);
  if (deg2 != id) {
    cout << "IMPOSSIBLE" << "\n";
    return;
  }
  sort(begin(id),end(id),[&](int i, int j){
    return deg[i] < deg[j];
  });
  for (int i=0;i<n;i++){
    cout << id[i] + 1 << " ";
  }
  cout << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
