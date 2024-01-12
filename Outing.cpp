#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Union Find using disjoint subset union
struct union_find {
  int n;
  vector<int> p;
  vector<int> sz;
  vector<int> ends;
  union_find(int n) : n(n), p(n), sz(n, 1), ends(n) {
    iota(begin(p),end(p), 0);
    iota(begin(ends),end(ends), 0);
  }
  int leader(int x) {
    if (p[x] == x)
      return x;
    return p[x] = leader(p[x]);
  }
  void unite(int x, int y) {
    int l = leader(x), s = leader(y);
    int e = ends[s];
    if (l == s) return;
    if (sz[s] > sz[l]) swap(s,l);
    p[s] = l, sz[l] += sz[s], ends[l] = e;
  }
};

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
    A[i]--;
  }
  union_find uf(n);
  for (int i=0;i<n;i++){
    uf.unite(i, A[i]);
  }
  vector<pair<int,int>> B;
  vector<int> vis(n);
  for (int i=0;i<n;i++){
    int g = uf.leader(i);
    if (vis[g]) continue;
    vis[g] = true;
    int start = uf.ends[g];
    int cur = A[start];
    int sz = 1;
    while (cur != start) {
      sz ++;
      cur = A[cur];
    }
    B.push_back({sz, uf.sz[g]});
  }
  vector<bool> dp(k+1);
  dp[0] = true;
  for (int i=0;i<B.size();i++){
    auto [mn, mx] = B[i];
    for (int j=k-1;j>=0;j--) {
      if (!dp[j]) continue;
      for (int d=mn;d<=mx;d++){
        if (j+d <= k) {
          dp[j+d] = true;
        }
      }
    }
  }
  int ans = 0;
  for (int i=0;i<=k;i++){
    if (dp[i]) ans = i;
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
