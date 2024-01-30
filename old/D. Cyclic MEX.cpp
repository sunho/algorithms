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
  int tgt =find(begin(A),end(A), 0) - begin(A);
  if (tgt != n-1) {
    rotate(begin(A), begin(A)+tgt+1, end(A));
  }
  ll ans = 0;
  ll sum = n;
  vector<pair<int,int>> mex = {{n,1}};
  for (int k=0;k<n1;k++) {
    int cnt = 0;
    while (!mex.empty() && mex.back().first >= A[k]) {
      sum -= (ll)mex.back().first * mex.back().second;
      cnt += mex.back().second;
      mex.pop_back();
    }
    sum += cnt * A[k];
    mex.push_back({A[k], cnt});
    mex.push_back({n,1});
    sum += n;
    ans = max(ans, sum);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
