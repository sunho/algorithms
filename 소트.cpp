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
  int s;
  cin >> s;
  for (int i=0;i<n;i++){
    pair<int,int> mx = {-1,-1};
    for (int t=0;t<=s && i+t<n;t++){
      mx = max(mx, {A[i+t], -t});
    }
    for (int j=i-mx.second-1;j>=i;j--){
      A[j+1]=A[j];
    }
    A[i] = mx.first;
    s += mx.second;
  }
  for (int i=0;i<n;i++){
    cout << A[i] << " ";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
