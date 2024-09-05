#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;

template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  vector<int> A(n);
  vector<int> deg(n);
  for (int i=0;i<n;i++){
    int m;
    cin >> A[i] >> m;
    for (int j=0;j<m;j++){
      int b;
      cin >> b;
      --b;
      adj[i].push_back(b);
      deg[b]++;
    }
  }
  pqg<pair<int,int>> pq;
  for (int i=0;i<n;i++){
    if (deg[i] == 0) {
      pq.push({A[i], i});
    }
  }
  int cnt = n-1;
  int ans = 0;
  while (!pq.empty()) {
    auto [a, i] = pq.top();
    pq.pop();
    ans = max(ans, cnt+a);
    cnt--;
    for (int v : adj[i]) {
      deg[v] -- ;
      if (deg[v] == 0) {
        pq.push({A[v], v});
      }
    }
  }
  cout << ans;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
