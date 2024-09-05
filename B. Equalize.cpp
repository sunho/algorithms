#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  sort(begin(A),end(A));
  A.resize(unique(begin(A),end(A))-begin(A));
  int m = (int)A.size();
  int ptr = 0;
  int ans = 0;
  for (int i=0;i<m;i++){
    while (ptr < m && A[i]+n-1 >= A[ptr]) {
      ptr++;
    }
    ans = max(ans, ptr-i);
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
