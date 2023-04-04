#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n;
  cin >> n;
  pair<int,int> s, t;
  cin >> s.first >> s.second >> t.first >> t.second;
  vector<pair<pair<int,int>, int>> circles(n);
  for (int i=0;i<n;i++){
    cin >> circles[i].first.first >> circles[i].first.second >> circles[i].second;
  }
  auto sq = [](int x) -> ll {
    return (ll)x*x;
  };
  vector<vector<int>> g(n);
  for (int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if (i == j) continue;
      auto [x1, y1] = circles[i].first;
      auto [x2, y2] = circles[j].first;
      int r1 = circles[i].second, r2 = circles[j].second;
      if (sq(x1-x2) + sq(y1-y2) >= sq(r1-r2) && sq(x1-x2) + sq(y1-y2) <= sq(r1+r2)) {
        g[i].push_back(j);
      }
    }
  }

  int u,v;
  for (int i=0;i<n;i++){
    auto [x1, y1] = circles[i].first;
    int r1 = circles[i].second;
    if (sq(x1-s.first) + sq(y1-s.second) == sq(r1)) {
      u = i;
    }
    if (sq(x1-t.first) + sq(y1-t.second) == sq(r1)) {
      v = i;
    }
  }
  vector<bool> vis(n);
  auto dfs = [&](int x, auto&& self) -> void{
    vis[x] = true;
    for (auto i : g[x]) {
      if (!vis[i])
        self(i, self);
    }
  };
  dfs(u, dfs);
  if (!vis[v]) {
    cout << "No" << "\n";
  } else {
    cout << "Yes" << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
