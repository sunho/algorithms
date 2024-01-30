#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,k,d;
  cin >> n >> k >> d;
  vector<int> A(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  vector<int> B(k);
  for (int i=0;i<k;i++){
    cin >> B[i];
  }
  int sum = 0;
  for (int i=0;i<n;i++){
    if (A[i] == i+1) {
      sum++;
    }
  }
  int ans = sum + (d-1)/2;
  for (int i=0;i<min(3*n,d);i++){
    for (int j=0;j<B[i%k];j++) {
      if (A[j] == j+1) {
        sum--;
      }
      if (A[j] == j) {
        sum++;
      }
      A[j]++;
    }
    if (d-i-1>=1) {
      ans = max(ans, sum + (d-i-2)/2);
    }
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
