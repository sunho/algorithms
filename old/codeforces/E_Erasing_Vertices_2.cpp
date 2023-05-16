#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,m;
  cin >> n >> m;
  
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }

  vector adj(n, vector<int>());

  for (int i=0;i<m;i++){
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<ll> sum(n);
  vector<bool> removed(n);
  set<pair<ll,int>> active;
  for (int i=0;i<n;i++){
    for (int u : adj[i]) {
      sum[i] += A[u];
    }
    active.insert({sum[i], i});
  }

  ll ans = 0;

  for (int t=0;t<n;t++){
    auto [s,u] = *active.begin();
    ans = max(ans, s);
    for (int v : adj[u]) {
      if (removed[v]) continue;
      active.erase({sum[v], v});
      sum[v] -= A[u];
      active.insert({sum[v], v});
    }
    active.erase({sum[u],u});
    A[u] = 0;
    removed[u] = true;
  }
  cout << ans;
}
