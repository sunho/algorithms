#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,l;
  cin >> n >> l;
  vector<array<int,2>> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i][0] >> A[i][1];
  }
  sort(begin(A),end(A));
  int end = 0;
  int ans = 0;
  for (int i=0;i<n;i++){
    int l1 = max(A[i][0],end);
    if (l1 >= A[i][1]) continue;
    int cnt = (A[i][1]-l1+l-1)/l;
    ans += cnt;
    end = max(end,l1+cnt * l);
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
