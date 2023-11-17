#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  if (k == 1) {
    cout << 0 << "\n";
    return;
  }
  const int N = (int)2e5+1;
  vector<array<vector<int>,2>> pos(N);
  for (int i=0;i<n;i++) {
    pos[A[i]][i%2].push_back(i);
  }
  ll del = 0;
  int m = n-(k+1)/2;
  for (int i=0;i<m;i++){
    auto& arr = pos[A[i]][i%2];
    int ranger = min({2+2*(m-i),k-1});
    int rangel = max({k-1-2*i,2});
    int r = upper_bound(begin(arr),end(arr),i+ranger) - begin(arr);
    int l = lower_bound(begin(arr),end(arr),i+rangel) - begin(arr);
    del += max(r-l,0);
  }
  cout << (ll)(k-1)/2*(n-k+1) - del << "\n";
}

int main() {
  solve();
}
