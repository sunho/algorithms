#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> g(n+1);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    g[a-1].push_back(b);
    g[b].push_back(a-1);
  }
  queue<int> q;
  vector<bool> vis(n+1);
  q.push(0);
  while(!q.empty()){ 
    int u = q.front();
    q.pop();
    for(int v : g[u]) {
      if (!vis[v]) {
        vis[v] = true;
        q.push(v);
      }
    }
  }
  if (vis[n]) {
    cout << "Yes" << "\n";
  } else {
    cout << "No" << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
