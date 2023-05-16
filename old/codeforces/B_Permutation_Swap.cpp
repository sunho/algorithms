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
    vector<int> A(n+1);
    for (int i=1;i<=n;i++) {
      cin >> A[i];
    }
    int ans = 0;
    for (int i=1;i<=n;i++) {
      ans = gcd(ans, abs(A[i] - i));
    }
    cout << ans << "\n";
  }
}
