#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  vector<int> B(m);
  for (int i = 0; i < m; i++) {
    cin >> B[i];
  }
  sort(begin(A), end(A));
  sort(begin(B), end(B));

  ll ans = -1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int w = A[j] - A[i];
      auto check = [&](int mid) { return (ll)w * B[mid] <= 2 * r; };
      int ok = -1, ng = m;
      while (ng - ok > 1) {
        int mid = (ok + ng) / 2;
        if (check(mid))
          ok = mid;
        else
          ng = mid;
      }
      if (ok != -1) {
        ans = max(ans, (ll)w * B[ok]);
      }
    }
  }
  if (ans == -1) {
    cout << -1 << "\n";
  } else {
    cout << ans / 2 << "." << (ans * 10 / 2) % 10 << "\n";
  }
}
