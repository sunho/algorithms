#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<ll> A(n);
  vector<ll> B(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  B[0] = A[0];
  for (int i=1;i<n;i++){
    B[i] = A[i]-A[i-1];
  }
  set<int> dirty;
  vector<ll> ans = B;
  int q;
  cin >> q;
  while (q--) {
    int l,r,x;
    cin >> l >> r >> x;
    --l,--r;
    dirty.insert(l);
    B[l] += x;
    if (r != n-1) {
      dirty.insert(r+1);
      B[r+1] -= x;
      if (B[r+1] == ans[r+1]) {
        dirty.erase(r+1);
      }
    }
    if (B[l] == ans[l]) {
      dirty.erase(l);
      if (!dirty.empty() && B[*dirty.begin()] < ans[*dirty.begin()]) {
        for (int i : dirty) {
          ans[i] = B[i];
        }
        dirty.clear();
      }
    } else if (*dirty.begin() == l && B[l] < ans[l]){
      for (int i : dirty) {
        ans[i] = B[i];
      }
      dirty.clear();
    }
  }
  ll cur = 0;
  for (int i=0;i<n;i++){
    cur += ans[i];
    cout << cur << " ";
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
