#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  auto f = [&](ll c) {
    int res = 0;
    int l = 0;
    while (l < n) {
      ll cur = A[l];
      if (cur > c) return false;
      while (l+1 < n && cur + A[l + 1] <= c) {
        cur += A[l+1];
        l++;
      }
      res++;
      l++;
    }
    return res <= k;
  };
  ll ng = -1, ok = 1e18;
  while (ok - ng > 1) {
    ll mid = (ok+ng) / 2;
    if (f(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
