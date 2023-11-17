#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> inv(n+1);
  for (int i=0;i<n;i++){
    cin >> A[i];
    inv[A[i]] = i;
  }
  int l = 0, r = n-1;
  set<int> rem;
  for (int i=1;i<=n;i++)
    rem.insert(i);
  while (l != r) {
    if (A[l] == *rem.begin() || A[l] == *--rem.end()) {
      rem.erase(A[l]);
      l++;
      continue;
    }
    if (A[r] == *rem.begin() || A[r] == *--rem.end()) {
      rem.erase(A[r]);
      r--;
      continue;
    }
    cout << l + 1 << " " << r + 1 << "\n";
    return;
  }
  cout << -1 << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
