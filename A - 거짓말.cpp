#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A;
  vector<int> B;
  for (int i=0;i<n;i++){
    int k;
    cin >> k;
    if (k <= 0) {
      A.push_back(-k);
    } else {
      B.push_back(k);
    }
  }
  sort(begin(A),end(A));
  sort(begin(B),end(B));
  vector<int> ans;
  for (int z=0;z<=n;z++){
    int cnt = lower_bound(begin(A),end(A),z)-begin(A);
    cnt += end(B)-upper_bound(begin(B),end(B),z);
    if (cnt == z) {
      ans.push_back(z);
    }
  }
  sort(begin(ans),end(ans));
  cout << ans.size() << "\n";
  for (int a : ans) {
    cout << a << " ";
  }
}

// z <= 0
// 

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
