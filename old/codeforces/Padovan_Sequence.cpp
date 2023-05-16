#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  const int N = 100;
  vector<ll> A(N);
  A[0] = 1;
  A[1] = 1;
  A[2] = 1;
  for (int i=3;i<N;i++){
    A[i] = A[i-2] + A[i-3];
  }  

  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    cout << A[n-1] << "\n";
  }
}
