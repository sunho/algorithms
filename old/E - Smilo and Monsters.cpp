#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i=0;i<n;i++){
      cin >> A[i];
    }
    sort(begin(A),end(A));
    int x = 0;
    int cur = n-1;
    long long ans = 0;
    for (int i=0;i<=cur;i++) {
      while (i < cur && A[cur]-x<=A[i]) {
        int req = A[cur]-x;
        cur--;
        ans += req + 1;
        A[i] -= req;
        x = 0;
      }
      if (i == cur) {
        if (A[i] <= 1) {
          ans += A[i];
        } else {
          if (x >= 1) {
            ans += (A[i] - x + 1)/2+1;
          } else {
            ans += (A[i]+1)/2+1;
          }
        }
      } else {
        x += A[i];
        ans += A[i];
      }
    }
    cout << ans << "\n";
  }
}
