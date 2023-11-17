#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> pos(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
    A[i] --;
    pos[A[i]] = i;
  }
  if (n == 1){
    cout << 0 << "\n";
    return;
  }
  const int inf = 1e9;
  int ans = inf;
  int last = pos[0];
  int beg = 0;
  for (int i=0;i<n;i++) {
    if (last > pos[i]) {
      ans = min(ans, max(beg, n-i));
      beg = i;
    }
    last = pos[i];
  }
  ans = min(ans, beg);
  if (ans == inf) {
    cout << 0 << "\n";
  } else {
    cout << ans << "\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
