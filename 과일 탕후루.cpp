#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  map<int, int> cnt;
  int r = 0;
  int ans = 0;
  for (int l = 0; l < n; l++) {
    while (r < n && (cnt.size() < 2 || cnt.count(A[r]))) {
      cnt[A[r]]++;
      r++;
    }
    ans = max(ans, r - l);
    cnt[A[l]]--;
    if (cnt[A[l]] == 0) {
      cnt.erase(A[l]);
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
