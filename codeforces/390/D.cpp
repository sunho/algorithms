#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define _0 first
#define _1 second
template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  queue<pair<int,int>> groups;
  vector<vector<bool>> visited(n, vector<bool>(m));
  queue<pair<int,int>> q;
  vector<vector<pair<int,int>>> p(n, vector<pair<int,int>>(m));
  vector<vector<int>> d(n, vector<int>(m,-1));
  q.push({0,0});
  visited[0][0] = true;
  groups.push({0,0});
  d[0][0] = 0;
  while(!q.empty()) {
    auto [i,j] = q.front();
    q.pop();
    pair<int,int> cords[] = {{i-1,j},{i+1,j},{i,j-1},{i,j+1}};
    for (auto [ni, nj] : cords) {
      if (ni < 0 || ni >=n || nj < 0 || nj >= m) continue;
      if (visited[ni][nj]) continue;
      visited[ni][nj] = true;
      groups.push({ni,nj});
      p[ni][nj] = {i,j};
      q.push({ni,nj});
    }
  }
  ll cost = 0;
  vector<deque<pair<int,int>>> ans;
  for(int i=0;i<k;i++) {
    ans.push_back({});
    auto u = groups.front();
    groups.pop();
    while (u != make_pair(0,0)) {
      ans.back().push_front(u);
      u = p[u._0][u._1];
      cost++;
    }
    cost++;
    ans.back().push_front({0,0});
  }
  cout << cost << "\n";
  for(int i=(int)ans.size()-1;i>=0;i--){
    for (auto u : ans[i]) {
      cout << "(" << u._0+1 << "," << u._1+1 << ") ";
    }
    cout << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
