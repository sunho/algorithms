#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  sort(begin(A),end(A));
  for (int i=0;i<n-1;i++){
    if (A[i] + 1 != A[i+1]) {
      cout << A[i] + 1 << "\n";
      return 0;
    }
  }
}
