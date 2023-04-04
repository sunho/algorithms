#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<bool> free(n);
  for (int i=0;i<m;i++) {
    int u,v;
    cin >> u >> v;
    --u,--v;
    if (u == -1) {
      free[v]=true;      
    } else {
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  const int INF = 1e9;
  vector<int> dis(n, INF);
  vector<int> dis2(n, INF);
  auto f = [&](vector<int>& dis, int s) {
    queue<int> q;
    dis[s] = 0;
    q.push(s);
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : g[u]) {
        if (dis[v] == INF) {
          dis[v] = dis[u] + 1;
          q.push(v);
        }
      }
    }
  };
  f(dis, 0);
  f(dis2, n-1);
  int mini_dis = INF;
  for (int i=0;i<n;i++){
    if (free[i]) {
      ckmin(mini_dis, dis2[i]);
    }
  }
  int mini_dis2 = INF;
  for (int i=0;i<n;i++){
    if (free[i]) {
      ckmin(mini_dis2, dis[i]);
    }
  }
  for(int i=0;i<n;i++){
    int ans = min({dis[n-1], dis[i] + mini_dis+1, dis2[i] + mini_dis2 + 1, mini_dis + mini_dis2 + 2});
    if (ans >= INF) {
      cout << -1 << " ";
    } else {
      cout << ans << " ";
    }

  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
