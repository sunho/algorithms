#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  vector<pair<int,int>> A(n);
  for (int i=0;i<n;i++){
    int x;
    cin >> x;
    A[i] = {x,i+1};
  }
  n++;
  A.push_back({0, 0});
  sort(begin(A), end(A));

  const int L = 29;

  vector adj(n, array<vector<int>, L>{});
  vector shown(n, array<bool,L>{});
  for (int z=0;z<L;z++) {
    int d = z == 0 ? 0 : (1 << (z-1));
    queue<pair<int,int>> points;
    set<pair<int,int>> pq;
    int right = 0;
    for (int i=0;i<n;i++){
      auto [x,j] = A[i];
      while (right < n && A[right].first >= x - d && A[right].first <= x + d) {
        auto [x2,j2] = A[right];
        if (j2 != 0) {
          points.push({x2,j2});
          pq.insert({j2,x2});
        }
        right++;
      }
      while (!points.empty() && points.front().first < x - d) {
        auto [x2,j2] = points.front();
        points.pop();
        pq.erase({j2,x2});
      }
      vector<int> visible;
      auto it = pq.end();
      for (int z=0;z<k;z++){
        if (it == pq.begin())
          break;
        --it;
        visible.push_back(it->first);
      }
      if (find(visible.begin(), visible.end(), j) != visible.end()) {
        shown[j][z] = true;
      }
      for (int v : visible) {
        if (v == j) continue;
        adj[j][z].push_back(v);
      }
    }
  }
  
  vector<array<int, L>> dist(n);
  for (auto & arr : dist) fill(arr.begin(), arr.end(), -1);
  dist[0][1] = 0;
  queue<pair<int,int>> q;
  q.push({0,1});
  while (!q.empty()) {
    auto [j,z] = q.front();
    q.pop();
    if (z != 0) {
      if (dist[j][z-1] == -1) {
        dist[j][z-1] = dist[j][z] + 1;
        q.push({j,z-1});
      }
    }
    if (z != L-1) {
      if (dist[j][z+1] == -1) {
        dist[j][z+1] = dist[j][z] + 1;
        q.push({j,z+1});
      }
    }
    for (int v : adj[j][z]) {
      if (dist[v][z] == -1) {
        dist[v][z] = dist[j][z] + 1;
        q.push({v,z});
      }
    }
  }
  for (int i=1;i<n;i++){
    int res = -1;
    for (int z=0;z<L;z++){
      if (shown[i][z] && dist[i][z] != -1 && (res == -1 || res > dist[i][z])) {
        res = dist[i][z];
      }
    }
    cout << res << "\n";
  }
}
