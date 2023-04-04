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
  int n,m,s,t;
  cin >> n >> m >> s >> t;
  --s,--t;
  vector<vector<pair<int,int>>> g(n);
  vector<vector<pair<int,int>>> g2(n);
  for (int i=0;i<m;i++){
    int u,v,a,b;
    cin >> u >> v >> a >> b;
    --u,--v;
    g[u].push_back({v,a});
    g[v].push_back({u,a});
    g2[u].push_back({v,b});
    g2[v].push_back({u,b});
  }
  vector<ll> dist1(n,-1);
  vector<ll> dist2(n,-1);
  auto calc = [&](auto& dist, auto& g, int s) {
    pqg<pair<ll,int>> pq;
    pq.push({0,s});
    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      if (dist[u] == -1) {
        dist[u] = d;
      } else {
        continue;
      }
      for (auto [v,w] : g[u]) {
        if (dist[v] == -1) {
          pq.push({d+w, v});
        }
      }
    }
  };
  calc(dist1, g, s);
  calc(dist2, g2, t);
  ll inf = 1e15;
  ll cand = inf;
  vector<ll> ans(n);
  for (int i=n-1;i>=0;i--){
    ckmin(cand, dist1[i] + dist2[i]);
    ans[i] = cand;
  }
  for (auto x : ans) {
    cout << inf - x << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
