#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> D(13);
  D[1] = D[3] = D[5] = D[7] = D[8] = D[10] = D[12] = 31;
  D[4] = D[6] = D[9] = D[11] = 30;
  D[2] = 28;
  auto cvt = [&](int m, int d) {
    int res = d-1;
    for (int i=1;i<m;i++){
      res += D[i];
    }
    return res;
  };
  const int M = cvt(12,31) + 1;
  vector<vector<int>> stk(M);
  for (int i=0;i<n;i++){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    stk[cvt(a,b)].push_back(cvt(c,d)-1);
  }
  int start = cvt(3,1);
  int end = cvt(11,30);
  int cur = 0;
  int mx = 0;
  int ans = 0;
  for (int i=0;i<=end;i++) {
    for (int e : stk[i]) {
      mx = max(mx, e);
    }
    if (i >= start) {
      if (cur < i) {
        if (mx < i) {
          cout << 0;
          return;
        }
        cur = mx;
        ans++;
      }
    }
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
