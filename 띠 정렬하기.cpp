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
  auto S = A;
  sort(begin(S),end(S));
  int ans = 0;
  for (int i=0;i<n;){
    ans ++;
    int cur = lower_bound(begin(S),end(S),A[i])-begin(S);
    int dir = -1;
    while (i < n) {
      i++;
      if (i == n) break;
      int nxt = lower_bound(begin(S),end(S),A[i])-begin(S);
      if (abs(nxt-cur) != 1) break;
      if (dir == -1) {
        dir = cur < nxt;
      } else if ((cur < nxt)!=dir) {
        break;
      }
      cur = nxt;
    }
  }
  cout << ans-1 << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
