#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,m,k;
  ll d;
  cin >> n >> m >> k >> d;
  --k;

  vector adj(n, vector<int>());
  for (int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  auto bfs = [&](int s) {
    vector<int> dist(n,-1);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        if(dist[v] == -1) {
          dist[v] = dist[u]+1;
          q.push(v);
        }
      }
    }
    return dist;
  };


  auto calc_score = [&](ll dist) {
    dist++;
    ll res = dist/d*d*(d+1)/2;
    ll rem = d - dist % d;
    res += d*(d+1)/2 - rem*(rem+1)/2;
    return res;
  };

  auto dist = bfs(k), dist2 = bfs(n-1);
  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
  vector<ll> score(n, -1);
  pq.push({0, 0});
  while (!pq.empty()) {
    auto [di, u] = pq.top();
    pq.pop();
    if (score[u] != -1)
      continue;
    score[u] = di;
    for (int v : adj[u]) {
      if (dist[v] >= d) {
        pq.push({di+calc_score(dist2[v]), n-1});
        continue;
      }
      if (score[v] != -1) continue;
      pq.push({di+(d-dist[v]), v});
    }
  }
  cout << score[n-1] << "\n";
}
