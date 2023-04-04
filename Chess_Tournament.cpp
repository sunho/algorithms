#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  set<pair<int,int>> pq;
  for (int i=0;i<n;i++){
    if (A[i] != 0)
      pq.insert({A[i],i});
  }
  vector<pair<int,int>> ans;
  for (int z=0;z<n && !pq.empty();z++){
    auto [rem, i] = *pq.begin();
    pq.erase(pq.begin());
    vector<pair<int,int>> to_add;
    for (int k =0; k < rem && !pq.empty(); ++k) {
      auto [rem, j] = *--pq.end();
      pq.erase(--pq.end());
      A[j]--;
      A[i]--;
      ans.push_back({j, i});
      if (A[j] != 0)
        to_add.push_back({A[j], j});
    }
    if (A[i] != 0) {
      cout << "IMPOSSIBLE" << "\n";
      return 0;
    }
    for (auto [r,j] : to_add) {
      pq.insert({r,j});
    }
  }
  cout << ans.size() << "\n";
  for (auto [u,v] : ans){
    cout << u + 1 << " " << v + 1 << "\n";
  }
}
