#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    vector<int> pf(n+1);
    for (int i=0;i<n;i++){
      int a;
      cin >> a;
      pf[i+1] = a;
    }
    for (int i=0;i<n;i++){
      pf[i+1] ^= pf[i];
    }
    set<int> pos;
    for (int a : pf) {
      pos.insert(a);
    }
    int ans = 0;
    for (int a : pos) {
      for (int b : pos) {
        ans = max(ans, a^b);
      }
    }
    cout << ans << "\n";
  }
}
