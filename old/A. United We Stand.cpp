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
    for (int i=0;i<n;i++) cin >> A[i];
    int mn = *min_element(begin(A), end(A));
    int mn_cnt = 0;
    for (int i=0;i<n;i++){
      if (A[i] == mn) mn_cnt++;
    }
    if (mn_cnt == n) {
      cout << -1 << "\n";
      continue;
    }
    cout << mn_cnt << " " << n-mn_cnt << "\n";
    for (int i=0;i<mn_cnt;i++){
      cout << mn << " ";
    }
    cout << "\n";
    for (int i=0;i<n;i++){
      if (A[i] != mn) cout << A[i] << " ";
    }
    cout << "\n";
  }
}
