#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i=0;i<n;i++){
      cin >> A[i];
    }
    ll ans = 0;   
    int cnt = 0;
    bool neg = false;
    for (int i=0;i<n;i++){
      if (A[i] < 0 && !neg) {
        neg = true;
        cnt ++;
      }
      if (A[i] > 0 && neg) {
        neg = false;
      }
      ans += abs(A[i]);
    }
    cout << ans << " " << cnt << "\n";
  }
}
