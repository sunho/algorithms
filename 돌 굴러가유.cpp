#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m, k;
  cin >> n >> k >> m;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<int> B(m);
  for (int i=0;i<m;i++){
    cin >> B[i];
    B[i]--;
  }
  vector<pair<int,int>> C;
  int ptr = 0;
  for (int i=0;i<n;i++){
    if (ptr < (int)B.size() && B[ptr] == i) {
      C.push_back({0,i});
      ptr++;
    }
    if (C.empty()) continue;
    C.back().first -= A[i];
  }
  sort(begin(C),end(C));
  vector<int> ans;
  for (int i=0;i<k;i++){
    ans.push_back(C[i].second);
  }
  sort(begin(ans),end(ans));
  for (int i : ans) {
    cout << i + 1 << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
