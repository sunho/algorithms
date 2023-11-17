#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  int ans = *max_element(begin(A),end(A));
  for (int i=0;i<n-1;i++){
    auto check = [&](int end) {
      int rem = k-(end-A[i]);
      if (rem < 0) return false;
      int last = end;
      for (int j=i+1;j<n;j++){
        if (A[j] >= last - 1)
          return true;
        int d = last - 1 - A[j];
        rem -= d;
        last--;
        if (rem < 0) return false;
      }
      return last <= A[n-1];
    };
    int ok = A[i], ng = (int)1e9+1;
    while (ng - ok > 1) {
      int mid = (ok+ng)/2;
      if (check(mid)) ok = mid;
      else ng = mid;
    }
    ans = max(ans, ok);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
