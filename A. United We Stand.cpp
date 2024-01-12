#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  sort(begin(A),end(A));
  if (A.back() == A[0]) {
    cout << -1 << "\n";
    return;
  }
  vector<int> B,C;
  for (int i=0;i<n;i++){
    if (A[i] == A.back()) {
      C.push_back(A[i]);
    } else {
      B.push_back(A[i]);
    }
  }
  cout << B.size() << " " << C.size() << "\n";
  for (int i=0;i<B.size();i++) {
    cout << B[i] << " ";
  }
  cout << "\n";
  for (int i=0;i<C.size();i++){
    cout << C[i] << " ";
  }
  cout << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
