#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> vals;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    vals.push_back(A[i]);
  }
  int m;
  cin >> m;
  vector<int> B(m);
  for (int i = 0; i < m; i++) {
    cin >> B[i];
    vals.push_back(B[i]);
  }
  sort(vals.begin(), vals.end());
  vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
  sort(vals.rbegin(), vals.rend());
  vector<int> ans;
  int l1 = 0, l2 = 0;
  while (l1 < n && l2 < m) {
    bool found = false;
    for (int k = 0; k < vals.size(); k++) {
      int x = find(A.begin() + l1, A.end(), vals[k]) - A.begin();
      int y = find(B.begin() + l2, B.end(), vals[k]) - B.begin();
      if (x == n || y == m)
        continue;
      found = true;
      ans.push_back(vals[k]);
      l1 = x + 1;
      l2 = y + 1;
      break;
    }
    if (!found)
      break;
  }
  cout << ans.size() << "\n";
  for (int a : ans) {
    cout << a << " ";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
