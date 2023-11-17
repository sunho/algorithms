#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> inv(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
    inv[A[i]-1] = i;
  }
  int q;
  cin >> q;
  for (int i=0;i<q;i++){
    int l,r;
    cin >> l >> r;
    --l;
    auto B = A;
    vector<int> C;
    for (int j=l;j<r;j++) {
      C.push_back(inv[j]);
    }
    sort(begin(C),end(C));
    for (int j=0;j<C.size();j++){
      B[C[j]] = l+j+1;
    }
    for (int j=0;j<n;j++){
      cout << B[j] << " ";
    }
    cout << "\n";
  }
}
