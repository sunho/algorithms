#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> A(2*n);
    for (int i=0;i<2*n;i++){
      cin >> A[i];
    }
    sort(begin(A),end(A));
    cout << A[n-1] - A[0] + A[2*n-1] - A[n] << "\n";
    for (int i=0;i<n;i++){
      cout << A[i] << " " << A[i+n] << "\n";
    }
  }
}
