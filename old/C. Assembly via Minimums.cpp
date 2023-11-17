#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  const int N = 1e9;
  while (t--){
    int n;
    cin >> n;
    int m = n*(n-1)/2;
    vector<int> A(m);
    for (int i=0;i<m;i++){
      cin >> A[i];
    }
    sort(begin(A),end(A));
    int cur = n;
    for (int i=0;i<m;i+=cur){
      cout << A[i] << " ";
      cur--;
    }
    cout << N << "\n";
  }
}
