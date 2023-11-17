#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i=0;i<n;i++) {
      cin >> A[i];
    }
    for (int i=0;i<n;i++) {
      if (A[i] == 1) {
        A[i]++;
      }
    }
    for (int i=0;i<n-1;i++) {
      if (A[i+1] % A[i] == 0) {
        A[i+1] ++;
      }
    }
    for (int i=0;i<n;i++) {
      cout << A[i] << " ";
    }
    cout << "\n";
  }
}
