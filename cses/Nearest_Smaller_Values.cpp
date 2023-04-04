#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<pair<int,int>> A(n);
  for (int i=0;i<n;i++) {
    int a;
    cin >> a;
    A[i] = {a,i};
  }
  sort(begin(A), end(A));
  vector<int> ans(n, -1);
  set<int> S;
  vector<int> to_add;
  int cur = 0;
  for (int i=0;i<n;i++){
    auto [a,j] = A[i];
    if (cur < a) {
      cur = a;
      for (int x : to_add)
        S.insert(x);
      to_add.clear();
    }
    auto it = S.upper_bound(j);
    if (it != S.begin()) {
      ans[j] = *--it;
    }
    to_add.push_back(j);
  }
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
