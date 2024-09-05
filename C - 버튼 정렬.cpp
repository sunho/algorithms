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
  int th = -1;
  for (int i=0;i<n-1;i++){
    if (A[i]>A[i+1]) {
      th = max(th, A[i]);
    }
  }
  vector<int> worklist = A;
  sort(rbegin(worklist),rend(worklist));
  int cur = -1;
  int cnt = 0;
  ll k;
  cin >> k;
  ll ans = 0;
  while (k && !worklist.empty()) {
    int a = worklist.back();
    worklist.pop_back();
    if (cnt == 0) {
      cnt = 1;
      cur = a;
      continue;
    }
    ll zz = min(k, (ll)cnt*(a-cur));
    if (cur >= th) {
      ans += zz/cnt;
    } else if (a == th && zz == (ll)cnt*(a-cur) && zz > 0) {
      ans++;
    }
    k -= zz;
    cur = a;
    cnt++;
  }
  ans += k/n;
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
