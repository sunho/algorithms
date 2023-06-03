#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  int ans = -1;
  for (int i=0;i<n;i++){
    int l = 1;
    while (i - l >= 0 && i + l < n && A[i-l] == A[i+l] && A[i-l] < A[i-l+1]) {
      l++;
    }
    if (l > 1) ans = max(ans, 2*l-1);
  }
  cout << ans << "\n";
}
