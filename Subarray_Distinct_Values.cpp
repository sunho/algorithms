#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  int l=0, r=0;
  ll ans = 0;
  map<int,int> cnt;
  int cur = 0;
  while (r < n) {
    if (cnt[A[r]] == 0)
      cur++;
    cnt[A[r]]++;
    r++;
    while (l < r && cur > x) {
      cnt[A[l]]--;
      if (cnt[A[l]] == 0) {
        cur--;
      }
      l++;
    }
    ans += (r-l);
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
