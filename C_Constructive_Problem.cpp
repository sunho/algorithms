#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  vector<int> vals(n+2);
  for (int i=0;i<n;i++){
    if (A[i] <= n)
      vals[A[i]]++;
  }
  int m;
  for (int a=0;a<=n;a++){
    if (!vals[a]) {
      m = a;
      break;
    }
  }
  if (!vals[m+1]) {
    int cnt = 0;
    for (int a=0;a<=m;a++){
      if (vals[a] > 1) {
        cout << "Yes" << "\n";
        return;
      }
      cnt += vals[a];
    }
    if (cnt < n) {
      cout << "Yes" << "\n";
    } else {
      cout << "No" << "\n";
    }
    return;
  }
  int mn = n, mx = 0;
  for (int i=0;i<n;i++){
    if (A[i] == m+1) {
      mn = min(i, mn);
      mx = max(i, mx);
    }
  }
  for (int i=mn;i<=mx;i++){
    if (A[i] <= n) {
      vals[A[i]]--;
      vals[m]++;
    }
  }
  int nm;
  for (int a=0;a<=n+1;a++){
    if (!vals[a]) {
      nm = a;
      break;
    }
  }
  if (nm == m+1) {
    cout << "Yes" << "\n";
  } else {
    cout << "No" << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--)
    solve();
}
