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
  int ans = n;
  int r = (n+1)/2;
  for (int i=0;i<n;i++){
    while (r < n && A[i] * 2 > A[r]) {
      r++;
    }
    if (r < n && A[i] * 2 <= A[r]) {
      ans--;
      r++;
    }
  }
  cout << ans;
}

// 2 2 3 5 6 7 8 9
//

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
