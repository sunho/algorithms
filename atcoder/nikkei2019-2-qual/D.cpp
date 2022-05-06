#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;


void solve() {
  int n,m;
  cin >> n >> m;
  vector<vector<pair<int,int>>> g(n);
  for(int i=0;i<m;i++){
    int l,r,w;
    cin >> l >> r >> w;
    --l,--r;
    g[l].push_back({r,w});
  }
  
  for(int i=0;i<n-1;i++){
    g[i+1].push_back({i,0});
  }
  vector<ll> dist(n, -1);
  pqg<pair<ll,int>> q;
  q.push({0, 0});
  while(!q.empty()) {
    auto [d, u] = q.top();
    q.pop();
    if (dist[u] == -1) {
      dist[u] = d;
    } else {
      continue;
    }
    for(auto [v,w] : g[u]) {
      if (dist[v] == -1) q.push({d+w, v});
    }
  }

  cout << dist[n-1] << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
