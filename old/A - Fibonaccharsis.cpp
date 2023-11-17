#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  auto check = [&](int b, int c) {
    int cnt = 2;
    int a=c-b;
    while (a >= 0 && a <= b) {
      c = b;
      b = a;
      a = c-b;
      cnt++;
    }
    return cnt >= k;
  };
  int ans = 0;
  for (int i=0;i<=n;i++){
    if (check(i, n)) {
      ans ++;
    }
  }
  cout << ans << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
