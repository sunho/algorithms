#include <bits/stdc++.h>
using namespace std;
using ll = long long;


#define dbg(x) "(" << #x <<": " << (x) << ") "
template<typename Ostream, typename T>
enable_if_t<is_same_v<Ostream,ostream>, Ostream&> 
operator<<(Ostream& os, const T& v){
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}

template<typename ...Ts>
ostream& operator<<(ostream& os, const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}

int main() {
  // freopen("input.txt", "r", stdin);
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,m,k;
  cin >> n >> m >> k;
  vector g(n, vector<pair<int,int>>());
  vector adj(n, set<int>());
  vector adj_inv(n, vector<int>());
  for (int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w; 
    --u,--v;
    g[u].push_back({v,w});
  }
  vector<ll> record(k);
  bool zero = false;
  for (int i=0;i<k;i++){
    cin >> record[i];
    if (record[i] == 0) zero = true;
  }
  if (!zero) record.push_back(0);
  sort(record.begin(), record.end());

  priority_queue<tuple<ll,int, int>, vector<tuple<ll,int,int>>, greater<>> pq;
  vector<ll> dist(n, -1);
  pq.push({0, 0, -1});
  while (!pq.empty()) {
    auto [di, u, p] = pq.top();
    pq.pop();
    if (dist[u] == di) {
      adj[p].insert(u);
      adj_inv[u].push_back(p);
    }
    if (dist[u] != -1)
      continue;
    if (p!=-1) {
      adj[p].insert(u);
      adj_inv[u].push_back(p);
    }
    dist[u] = di;
    for (auto [v,w] : g[u]) {
      if (dist[v] == di+w) {
        adj[u].insert(v);
        adj_inv[v].push_back(u);
      } else if (dist[v] == -1) {
        pq.push({di+w, v, u});
      }
    }
  }

  set<pair<ll,int>> rem;
  map<ll,int> cnt;
  for (int i=0;i<n;i++){
    cnt[dist[i]]++;
    rem.insert({dist[i], i});
  }

  auto remove = [&](auto self, int u, int s) -> void {
    cnt[dist[u]]--;
    rem.erase({dist[u],u});
    for (int v : adj_inv[u]) {
      if (v == s) continue;
      if (adj[v].count(u)) {
        adj[v].erase(u);
        if (adj[v].empty()) {
          self(self, v, s);
        }
      }
    }
  };

  for (int i=0;i<n-1;i++) {
    if (adj[i].empty()) {
      remove(remove, i, -1);
    }
  }

  vector<int> path;
  int cur = n-1;
  path.push_back(n-1);
  while (!record.empty()) {
    ll d = record.back();
    record.pop_back();
    int u;
    if (cnt[d] <= 0) {
      cout << 0 << "\n";
      return 0;
    } else if (cnt[d] > 1) {
      cout << 1 << "\n";
      return 0;
    } else {
      u = rem.lower_bound({d,0})->second;
    }
    // cout << dbg(rem) << "\n";
    if (u == n-1) {
      continue;
    }
    // cout << dbg(u) dbg(adj[u]) << "\n";
    stack<int> to_push;

    int s = u;
    while (u != cur) {
      if (adj[u].empty()) {
        cout << 0 << "\n";
        return 0;
      } else if (adj[u].size() > 1) {
        cout << 1 << "\n";
        return 0;
      } else {
        to_push.push(u);
        u = *adj[u].begin();
      }
    }
    remove(remove, cur, s);
    cur = s;
    while (!to_push.empty()) {
      path.push_back(to_push.top());
      to_push.pop();
    }
  }
  cout << path.size() << "\n";
  reverse(path.begin(), path.end());
  for (int v : path) {
    cout << v + 1 << "\n";
  }
}