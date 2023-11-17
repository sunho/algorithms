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
    vector<int> A(n);
    for (int i=0;i<n;i++){
      cin >> A[i];
    }
    int ans = 1e9;
    for (int a : A) {
      vector<int> B = A;
      for (int& b : B) {
        b = max(b-a, 0);
      }
      if (is_sorted(begin(B),end(B))) ans = min(ans,a);
    }
    if (is_sorted(begin(A), end(A))) ans = 0;
    cout << ans << "\n";
  }
}
