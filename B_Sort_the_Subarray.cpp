#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  for (int i=0;i<n;i++) cin >> A[i];
  for (int i=0;i<n;i++) cin >> B[i];
  int mn = n;
  int mx = 0;
  for (int i=0;i<n;i++) {
    if (A[i] != B[i]) {
      mn = min(mn, i);
      mx = max(mx, i);
    }
  }
  if (mn == n) {
    mn = 0;
    mx = n;
  }
  tuple<int,int,int> ans = {0,0,0};
  int cur = 1;
  int start = 0;
  int last = B[0];
  for (int i=1;i<n;i++){
    if (B[i] < last) {
      if (start <= mn && mx <= i)
        ans = max(ans, {cur, start, i});
      cur = 1;
      start = i;
    } else {
      cur ++;
    }
    last = B[i];
  }
  if (cur != 0) {
    if (start <= mn && mx <= n)
      ans = max(ans, {cur, start, n});
  }
  auto [_,l,r] = ans;
  cout << l + 1 << " " << r << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
