#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  const int inf = (int)1e9 + 10;
  vector<int> pf(n+1, inf);
  for (int i=n-1;i>=0;i--){
    pf[i] = min(pf[i+1], A[i]);
  }
  int ans = 0;
  int cnt = 0;
  int cur = 0; 
  for (int i=0;i<n;i++){
    cur = max(cur, A[i]);
    if (cur < pf[i+1]) {
      ans += cnt;
      cnt = 0;
      cur = 0; 
    } else {
      cnt++;
    }
  }
  ans += cnt;
  cout << ans << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
