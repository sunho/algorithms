#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  ll k;
  cin >> n >> k;
  deque<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  int ans = 0;
  while (!A.empty() && k) {
    if (A.size() == 1) {
      if (A.front() <= k) {
        ans ++;
      }
      break;
    }
    int a = min(A.front(),A.back())-1;
    ll kk = (ll)2*a;
    if (kk <= k) {
      k -= kk;
      A.front() -= a;
      A.back() -= a;
    } else {
      break;
    }
    if (k) {
      k--;
      A.front()--;
      if (A.front() == 0) {
        A.pop_front();
        ans++;
      }
    }
    if (k) {
      k--;
      A.back()--;
      if (A.back() == 0) {
        A.pop_back();
        ans++;
      }
    }
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
