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
  vector<vector<tuple<int,int,int>>> G(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    int w,w2;
    cin >> w >> w2;
    --a,--b;
    G[a].push_back({b,w,w2});
    G[b].push_back({a,w,w2});
  }
  
  vector<ll> dist(n, -1);
  pqg<pair<ll, int>> pq;
  pq.push({0, 0});
  while(!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (dist[u] == -1) {
      dist[u] = d;
    } else {
      continue;
    }
    for (auto [v, w, w2] : G[u]) {
      // t + D/(t+1)
      // sqrt(D) - 1 + D/(sqrt(D))
      // 1  = D/(t+1)^2
      // D = (t+1)^2
      // sqrt(D) - 1
      // 1 + D/(1+1)
      int ww = (int)sqrt(w2);
      ll nd;
      if (d < ww) {
        nd = ww + w2/(ww+1) + w;
      } else {
        nd = d + w + w2/(d+1);
      }
      pq.push({nd, v});
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
