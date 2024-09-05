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
  vector<int> B = {A[0], A[(int)A.size()-1], A[1], A[(int)A.size()-2]};
  int ans = 0;
  for (int i=0;i<4;i++){
    ans += abs(B[(i+1)%4]-B[i]);
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
