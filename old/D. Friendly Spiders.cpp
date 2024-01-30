#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  const int N = (int)3e5;
  vector<int> mp(N+1, -1);
  for (int i=0;i<n;i++) {
    cin >> A[i];
    mp[A[i]] = i;
  }
  vector<vector<int>> adj(N+1);
  vector<vector<int>> comps(N+1);
  for (int i=2;i<=N;i++) {
    for (int j=i;j<=N;j+=i) {
      if (mp[j] != -1) {
        adj[i].push_back(j);
        comps[j].push_back(i);
      }
    }
  }
  int s,t;
  cin >> s >> t;
  --s,--t;
  if (s==t) {
    cout << 1 << "\n";
    cout << s + 1 << "\n";
    return;
  }
  if (A[s] == 1 || A[t] == 1) {
    cout << -1 << "\n";
    return;
  }
  if (gcd(A[s],A[t])!=1) {
    cout << 2 << "\n";
    cout << s + 1 << " " << t + 1 << "\n";
    return;
  }
  vector<int> dist(N+1, -1);
  vector<int> prev(N+1, -1);
  queue<int> q;
  dist[A[s]] = 0;
  q.push(A[s]);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int j : comps[u]) {
      for (int v : adj[j]) {
        if (dist[v] == -1) {
          dist[v] = dist[u] + 1;
          prev[v] = u;
          q.push(v);
        }
      }
      adj[j].clear();
    }
  }
  if (dist[A[t]] == -1) {
    cout << -1 << "\n";
    return;
  }
  cout << dist[A[t]] + 1 << "\n";
  vector<int> path;
  int cur = A[t];
  while (cur != A[s]) {
    path.push_back(mp[cur]);
    cur = prev[cur];
  }
  path.push_back(mp[A[s]]);
  reverse(begin(path),end(path));
  cout << s+1 << " ";
  for (int i=1;i<path.size()-1;i++) {
    cout << path[i] + 1 << " ";
  }
  cout << t+1 << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
