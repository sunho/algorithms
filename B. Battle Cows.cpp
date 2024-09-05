#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,k;
  cin >> n >> k;
  --k;
  vector<int> A(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  int a = A[k];
  int pos = -1;
  int ans = 0;
  for (int i=0;i<k;i++){
    if (a < A[i]) {
      pos = i;
      break;
    }
  }
  if (pos != -1) {
    swap(A[pos], A[k]);
    int cc=pos==0?0:1;
    ans = max(ans, cc);
    for (int i=pos+1;i<n;i++){
      if (a < A[i]) {
        break;
      }
      ans = max(ans, ++cc);
    }
    swap(A[pos], A[k]);
  }
  swap(A[0], A[k]);
  for (int i=1;i<n;i++){
    if (a < A[i]) {
      break;
    }
    ans = max(ans, i);
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
