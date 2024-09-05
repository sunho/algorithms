#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  deque<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  int ans = 0;
  for (int i=0;i<n;i++){
    int a_s = A[i];
    int j = i;
    int cnt = 0;
    while (j < n) {
      int nj = (int)(lower_bound(begin(A),end(A),2*A[j]-a_s)-begin(A));
      if (2*A[j] - a_s == A[j]) {
        int nj2 = (int)(upper_bound(begin(A),end(A),2*A[j]-a_s)-begin(A));
        cnt += nj2-j;
        nj = nj2;
      } else {
        cnt ++;
      }
      j = nj;
    }
    ans = max(ans, cnt);
  }
  cout << n-ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
