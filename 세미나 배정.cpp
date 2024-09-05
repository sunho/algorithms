#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// mx
//
// 1 2 3 4 5
// 1 2 3 4 5
//
//
//
//     3 4 5 6 7
// 1 2 3 4 5
//
//

// r[0] = -inf
// max(r[max(i-cost,0)]+1, ai-T+1)
// 

void solve() {
  int n, t;
  cin >> n >> t;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
    A[i]--;
  }
  ranges::sort(A);
  const int inf = 1e9 + 100;
  auto check = [&](int lim) {
    vector<int> R;
    R.push_back(-1);
    for (int i=0;i<n;i++){
      int mm = R[max((int)R.size()-lim,0)];
      if (mm+1 > A[i]) return false;
      R.push_back(max(mm+1, A[i]-t+1)+t-1);
    }
    return true;
  };
  int ng = 0, ok = n+1;
  while (ok - ng > 1) {
    int mid = (ok+ng)/2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
