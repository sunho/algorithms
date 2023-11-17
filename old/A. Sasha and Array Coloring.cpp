#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i=0;i<n;i++){
      cin >> A[i];
    }
    sort(begin(A),end(A));
    ll ans = 0;
    for (int i=0;i<n/2;i++){
      ans += A[n-i-1] - A[i];   
    }
    cout << ans << "\n";
  }
}
