#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  
  int n,m;
  cin >> n >> m;
  vector adj(n, set<int>());
  vector<int> deg(n);
  while (m--) {
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].insert(v);
    adj[v].insert(u);
    deg[u]++;
    deg[v]++;
  }

  for (int i=0;i<n;i++){
    if (deg[i] % 2 != 0) {
      cout << "IMPOSSIBLE" << "\n";
      return 0;
    }
  }

  vector<int> ans;
  stack<int> st;
  st.push(0);
  while (!st.empty()){
    int u = st.top();
    if (!adj[u].empty()) {
      int v = *adj[u].begin();
      adj[u].erase(v);
      adj[v].erase(u);
      st.push(v);
    } else {
      st.pop();
      ans.push_back(u);
    }
  }
  for (int i=0;i<n;i++){
    if (!adj[i].empty()) {
      cout << "IMPOSSIBLE" << "\n";
      return 0;
    }
  }
  for (int v : ans) {
    cout << v + 1 << " ";
  }

}
