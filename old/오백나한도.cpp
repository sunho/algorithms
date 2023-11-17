#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  ll k;
  cin >> k;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  int mx = *max_element(begin(A),end(A));
  const ll inf = 2e18;
  vector<ll> dist(mx, inf);
  vector<int> inv(mx+1, -1);
  for (int i=0;i<n;i++){
    inv[A[i]] = i;
  }
  vector<ll> prev(mx, -1);
  priority_queue<pair<ll,int>> pq;
  dist[0] = 0;
  pq.push({0,0});
  while (!pq.empty()) {
    auto [d,u] = pq.top();
    pq.pop();
    d *= -1;
    if (dist[u] < d) {
      continue;
    }
    for (int i=0;i<n;i++){
      ll nd = d + A[i];
      int v = (u + A[i]) % mx;
      if (dist[v] > nd) {
        dist[v] = nd;
        prev[v] = u;
        pq.push({-nd, v});
      }
    }
  }
  for (int j=0;j<mx;j++) {
    if (dist[j] != inf && (k - dist[j]) % mx == 0 && dist[j] <= k) {
      vector<ll> ans(n);
      int cur = j;
      while (cur != -1) {
        int nxt = prev[cur];
        if (nxt != -1) {
          int a = dist[cur] - dist[nxt];
          ans[inv[a]]++;
        }
        cur = nxt;
      }
      ans[inv[mx]] += (k - dist[j])/mx;
      for (int i=0;i<n;i++){
        cout << ans[i] << " ";
      }
      return 0;
    }
  }
  cout << -1 << "\n";
}
