#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector<pair<int,int>> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
  }

  vector<int> B(m);
  for (int i=0;i<m;i++){
    cin >> B[i];
  }

  sort(rbegin(B),rend(B));
  sort(begin(A),end(A),[](auto a, auto b){
    return a.second > b.second;
  });
  int l = 0;
  int ans = 0;
  for (int i=0;i<m;i++){
    int a = B[i];
    while (l < n && A[l].first > a) {
      cout << l;
      l++;
    }
    if (l != n) {
      ans ++;
      l++;
    }
  }
  cout << ans;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
