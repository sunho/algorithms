#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = 0;
    for (int i=0;i<n;i++){
      vector<int> A(n);
      for (int j=0;j<i;j++){
        A[j] = j+1;
      }
      for (int j=i;j<n;j++){
        A[j] = n-j+i;
      }
      int cand = 0;
      int mx = 0;
      for (int j=0;j<n;j++){
        cand += A[j] * (j+1);
        mx = max(mx, A[j]*(j+1));
      }
      cand -= mx;
      ans = max(ans, cand);
    }
    cout << ans << "\n";
  }
}
