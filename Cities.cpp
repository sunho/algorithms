#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

ll dist[100005][35];
vector<pair<int,int>> adj[100005];
void solve() {
  int n,k,m;
  cin >> n >> k >> m;
  vector<int> A(k);
  for (int i=0;i<k;i++){
    cin >> A[i];
    A[i]--;
  }
  for (int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    --u,--v;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }

  const int N = 1 << k;
  pqg<pair<ll,int>> pq;
  const ll inf = 1e18;
  for (int i=0;i<n;i++){
    for (int msk=0;msk<N;msk++) {
      dist[i][msk] = inf;
    }
  }
  for (int i=0;i<k;i++) {
    dist[A[i]][1<<i] = 0;
    pq.push({0,(A[i]<<5)|(1<<i)});
  }
  for (int z=0;z<3;z++){
    if (z != 0) {
      for (int u=0;u<n;u++) {
        for (char msk=1;msk<N;msk++){
          if (__builtin_popcount(msk) A
          for (char prev=1;prev<N;prev++) {
            if ((msk & prev) != prev) continue;
            ll nd = dist[u][prev] + dist[u][msk^prev];
            if (nd > inf) continue;
            if (dist[u][msk] > nd) {
              dist[u][msk]=nd;
              if (msk!=N-1)
                pq.push({nd,(u<<5)|(msk)});
            }
          }
        }
      }
    }
    while (!pq.empty()) {
      auto [d, u] = pq.top();
      int msk = u & ((1<<5)-1);
      u >>= 5;
      pq.pop();
      if (dist[u][msk] != d) continue;
      for (auto [v,w] : adj[u]) {
        ll nd = d + w;
        if (dist[v][msk] > nd) {
          dist[v][msk] = nd;
          pq.push({nd, (v<<5)|msk});
        }
      }
    }
  }
  ll ans = inf;
  for (int i=0;i<n;i++){
    ans = min(ans, dist[i][N-1]);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}

