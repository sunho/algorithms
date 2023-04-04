#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector adj(1<<(n-1), vector<int>());
  const int cover_mask = ((1<<(n-1)) - 1);
  for (int u=0;u<(1<<(n-1));u++){
    adj[u].push_back(((u << 1) | 1) & cover_mask);
    adj[u].push_back((u << 1) & cover_mask);
  }
  if (n == 1){
    cout << "01" << "\n";
    return 0;
  }
  string ans;
  auto walk = [&](auto self, int u) -> void {
    while (!adj[u].empty()) {
      int v = adj[u].back();
      adj[u].pop_back();
      self(self, v);
      ans.push_back('0'+(v & 1));
    }
  };
  walk(walk, 0);
  for (int i=0;i<n-1;i++){
    ans.push_back('0');
  }
  cout << ans << "\n";
}
