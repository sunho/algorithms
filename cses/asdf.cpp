#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n,m;
  vector<vector<char>> M(n, vector<char>(m));
  queue<tuple<int,int,int>> q;
  q.push({M[0][0],0,0});
  set<tuple<int,int,int>> visited;
  int ans = 0;
  while(!q.empty()) {
    auto [gift, x, y] = q.front();
    q.pop();
    vector<pair<int,int>> cands = { {x,y+1}, {x+1,y}, {x-1,y}, {x,y-1}};
    for (auto [x2, y2] : cands) {
      if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) continue;
      char C = M[x2][y2];
      if (gift & (1<<(C-'A'))) continue; // 중복
      int gift2 = gift | (1<<(C-'A'));
      if (visited.count({gift2, x2, y2})) continue;
      if (x2 == n - 1 && y2 == m - 1) {
        ans = max(ans, popcount(gift2));
      }
      q.push({gift2, x2, y2});
      visited.insert({gift2, x2, y2});
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;

}