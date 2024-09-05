#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  for (int i=0;i<n;i++){
    cin >> B[i];
  }
  deque<pair<ll,ll>> cur;
  const ll inf = 1e18;
  ll sum = inf;
  cur.push_back({-inf,inf});
  ll ans = inf;
  for (int i=0;i<n;i++){
    ll rem = sum - B[i];
    while (rem > 0) {
      auto [a, x] = cur.front();
      ll k = min(rem, x);
      rem -= k;
      sum -= k;
      if (a != -inf) {
        ans = min(ans, A[i]-a-1);
      }
      cur.front().second -= k;
      if (cur.front().second == 0) {
        cur.pop_front();
      }
    }
    ll nw = B[i] - sum;
    if (nw > 0) {
      cur.push_back({A[i-1]+1, nw});
      sum += nw;
    }
  }
  if (ans == inf) {
    cout << -1;
  } else {
    cout << ans;
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
