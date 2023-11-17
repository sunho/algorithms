#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int t;
  cin >> t;
  while (t--){
    int x,y,n;
    cin >> x >> y >> n;
    vector<int> A(n);
    A[0] = y;
    A[n-1] = x;
    int k = 1;
    for (int i=1;i<n-1;i++){
      A[i] = A[i-1] - (k++);
    }
    if (A[n-2] - A[n-1] < k) {
      cout << -1 << "\n";
      continue;
    }
    reverse(begin(A),end(A));
    for (int a : A) {
      cout << a << " ";
    }
    cout << "\n";
  }
}
