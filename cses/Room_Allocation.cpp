#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<pair<int,int>> A(n);
  vector<int> id(n);
  iota(begin(id), end(id), 0);
  for (int i=0;i<n;i++){
    cin >> A[i].second >> A[i].first;
  }
  vector<int> ans(n);
  set<pair<int,int>> groups;
  sort(begin(id), end(id), [&](int i, int j) {
    return A[i] < A[j];
  });
  sort(begin(A),end(A));
  for (int i=0;i<n;i++){
    auto [r,l] = A[i];
    auto it = groups.lower_bound({l, 0});
    if (it == groups.begin()) {
      ans[id[i]] = groups.size();
      groups.insert({r, groups.size()});
    } else {
      --it;
      int gid = it->second;
      groups.erase(it);
      groups.insert({r, gid});
      ans[id[i]] = gid;
    }
  }
  cout << groups.size() << "\n";
  for (int i=0;i<n;i++){
    cout << ans[i] + 1 << " ";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
