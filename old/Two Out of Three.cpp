#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  map<int,int> cnt;
  for (int i=0;i<n;i++){
    cin >> A[i];
    cnt[A[i]]++;
  }
  set<int> used;
  for (auto [k, c] : cnt) {
    if (c >= 2) {
      if (used.size() < 2) {
        used.insert(k);
      }
    }
  }
  if (used.size() != 2) {
    cout << -1 << "\n";
    return;
  }
  vector<int> B(n, 1);
  bool state = false;
  int k = *used.begin();
  for (int i=0;i<n;i++) {
    if (A[i] == k) {
      if (!state) {
        B[i] = 1;
        state = true;
      } else {
        B[i] = 2;
      }
    }
  }
  state = false;
  k = *(++used.begin());
  for (int i=0;i<n;i++) {
    if (A[i] == k) {
      if (!state) {
        B[i] = 1;
        state = true;
      } else {
        B[i] = 3;
      }
    }
  }
  for (int i=0;i<n;i++) {
    cout << B[i] << " ";
  }
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
