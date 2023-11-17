#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  if (!is_sorted(begin(A),end(A))) {
    cout << "No" << "\n";
    return 0;
  }
  if (A.back() != n+1) {
    cout << "No" << "\n";
    return 0;
  }
  vector<int> B(n);
  set<int> avail;
  for (int i=1;i<=n;i++){
    avail.insert(i);
  }
  set<int> vis;
  for (int i=n-1;i>=1;i--){
    if (!vis.count(A[i-1])) {
      B[i] = A[i-1];
      vis.insert(A[i-1]);
      avail.erase(A[i-1]);
    }
  }
  for (int i=0;i<n;i++){
    if (!B[i]) {
      B[i] = *avail.begin();
      avail.erase(avail.begin());
    }
  }
  bool ok = true;
  vis.clear();
  int cur_mex = 1;
  for (int i=0;i<n;i++){
    vis.insert(B[i]);
    while (vis.count(cur_mex)) {
      cur_mex++;
    }
    if (cur_mex != A[i]) {
      ok = false;
    }
  }
  if (!ok) {
    cout << "No" << "\n";
    return 0;
  }
  cout << "Yes" << "\n";
  for (int i=0;i<n;i++){
    cout << B[i] << " ";
  }
}
