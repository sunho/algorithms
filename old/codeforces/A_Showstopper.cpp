#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  for(int i=0;i<n;i++){
    cin >> B[i];
  }
  if (A.back() > B.back()) {
    swap(A[A.size()-1], B[B.size()-1]);
  }
  for (int i=0;i<n-1;i++){
    if (A[i] > A[n-1]) {
      swap(A[i], B[i]);
    }
  }
  if (*max_element(begin(A),end(A)) == A[n-1] && *max_element(begin(B), end(B)) == B[n-1]) {
    cout << "Yes" << "\n";
  } else {
    cout << "No" << "\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
