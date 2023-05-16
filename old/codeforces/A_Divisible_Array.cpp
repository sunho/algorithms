#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> A(n);
    int sum = 0;
    for (int i=1;i<n;i++){
      A[i] = i+1;
      sum += i + 1;
    }
    A[0] = (n-sum % n) + n;
    for (int i=0;i<n;i++){
      cout << A[i] << " ";
    }
    cout << "\n";
  }

}
