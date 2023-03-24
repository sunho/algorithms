#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, t;
  cin >> n >> t;
  vector<int> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  auto f = [&](ll cur) {
    ll rem = t;
    for (int i=0;i<n;i++){
      rem -= cur/A[i];
      if (rem <= 0) {
        return true;
      }
    }
    return false;
  };
  ll ng = -1, ok = 1e18+1;
  while (ok-ng > 1) {
    ll mid = (ok+ng)/2;
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
