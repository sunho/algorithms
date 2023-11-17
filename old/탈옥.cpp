#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> pf(n+1);
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  for (int i=0;i<n;i++){
    pf[i+1] = pf[i] + A[i];
  }
  auto cost = [&](int l, int r) {
    return (r-l+1)*(pf[r+1]-pf[l]);
  };
  vector<ll> dp_old(n), dp_cur(n);
  auto solve = [&](auto&& self, int l, int r, int optl, int optr) -> void {
    if (l > r)
      return;
    int mid = (l+r)/2;
    pair<ll, int> best = {LLONG_MAX, -1};
    for (int k=optl;k<=min(mid,optr);k++){
      best = min(best, {(k?dp_old[k-1]:0) + cost(k,mid), k});
    }
    dp_cur[mid] = best.first;
    int opt = best.second;
    self(self, l, mid-1, optl, opt);
    self(self, mid+1, r, opt, optr);
  };
  for (int i=0;i<n;i++){
    dp_old[i] = cost(0,i);
  }
  for (int i=1;i<k;i++){
    solve(solve,0,n-1,0,n-1);
    dp_old = dp_cur;
  }

  cout << dp_old[n-1];
}

