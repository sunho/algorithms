#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m,k;
  cin >> n >> m >> k;
  vector A(n, 0);
  vector B(m, 0);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  for (int i=0;i<m;i++){
    cin >> B[i];
  }
  sort(begin(A), end(A));
  sort(begin(B), end(B));
  int ans = 0;
  int j = 0;
  for (int i=0;i<n;i++){
    while (j < m && A[i] - k > B[j]) {
      j++;
    }
    if (j < m && B[j] <= A[i] + k) {
      ans ++;
      j++;
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
