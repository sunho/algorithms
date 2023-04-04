#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector A(n,0);
  for(int i=0;i<n;i++) cin >> A[i];
  int l=-1, r = 1e9+1;
  auto f = [&](int x) {
    ll res = 0;
    for (int i=0;i<n;i++){
      res += abs(A[i] - x);
    }
    return res;
  };
  while (r-l > 1) {
    int mid = (r+l) >> 1;
    if (f(mid) < f(mid+1)) 
      r = mid;
    else
      l = mid;
  }
  cout << f(l+1) << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
