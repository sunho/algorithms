#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,k;
  cin >> n >> k;
  int m;
  cin >> m;
  vector<pair<int,int>> edges(m);
  for (int i=0;i<m;i++) {
    cin >> edges[i].first >> edges[i].second;
    edges[i].first--;
    edges[i].second--;
  }
  if (n > 8) {
    cout << 0 << "\n";
    return;
  }
  vector<int> A(n);
  iota(begin(A),end(A),1);
  int ans = 0;
  do {
    bool ok = true;
    for (auto [x,y] : edges) {
      if (A[x]+A[y] > k) ok = false;
    }
    if (ok) ans++;
  } while (next_permutation(begin(A),end(A)));
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  for (int t=0;t<T;t++){
    cout << "Case #" << t+1 << "\n";
    solve();
  }
}
