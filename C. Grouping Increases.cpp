#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  if (n <= 2) {
    cout << 0 << "\n";
    return;
  }
  const int inf = 1e9;
  array<int,2> cur= {A[0], inf};
  sort(begin(cur),end(cur));
  int ans = 0;
  for (int i=1;i<n;i++) {
    if (cur[1] < A[i]) {
      ans++;
      cur[0] = A[i];
    } else {
      if (cur[0] >= A[i]) {
        cur[0] = A[i];
      } else {
        cur[1] = A[i];
      }
    }
    sort(begin(cur),end(cur));
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
