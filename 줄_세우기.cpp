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
  vector<vector<int>> g(n);
  vector<int> deg(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    --a,--b;
    g[a].push_back(b);
    deg[b]++;
  }

  queue<int> q;
  for(int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      q.push(i);
    }
  }

  vector<int> order;
  int cnt = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    cnt++;
    order.push_back(u);
    for(auto v : g[u]) {
      if (--deg[v] == 0) {
        q.push(v);
      }
    }
  }

  for(int i=0;i<n;i++){
    cout << order[i] + 1 << " ";
  }
  cout << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
