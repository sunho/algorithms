#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  array<int, 3> costs;
  int n, m;
  cin >> n >> m >> costs[0] >> costs[1] >> costs[2];
  array<array<char, 50>, 50> adj{}, cur_adj{};
  vector cost_adj(3, array<array<char, 50>, 50>{});
  while(m--){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[v][u] = 1;
  }
  cur_adj = adj;
  for (int t=0;t<=100;t++){
    for (int c=0;c<3;c++){
      if (t+1 == costs[c]) cost_adj[c] = cur_adj;
    }
    array<array<char, 50>, 50> next{};
    for (int k=0;k<n;k++){
      for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
          next[i][j] |= cur_adj[i][k] && adj[k][j];
        }
      }
    }
    cur_adj = next;
  }
  int turn = 1;
  set<int> goals;
  goals.insert(n-1);
  while(true) {
    set<int> next_goals;
    for (int j=0;j<n;j++){
      if (!goals.count(j)) {
        array<bool,3> oks{};
        for (int v : goals) {
          for (int c = 0; c<3; c++){
            if (cost_adj[c][v][j]) oks[c] = true;
          }
        }
        if (oks[0] && oks[1] && oks[2]) {
          next_goals.insert(j);
        }
      }
    }
    if (next_goals.empty()) {
      cout << "IMPOSSIBLE" << "\n";
      return;
    }
    if (next_goals.count(0)) {
      cout << turn << "\n";
      return;
    }
    turn++;
    goals.insert(begin(next_goals), end(next_goals));
  }

}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
