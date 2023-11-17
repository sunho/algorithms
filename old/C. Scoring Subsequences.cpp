#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i=0;i<n;i++){
      cin >> A[i];
    }
    for (int i=0;i<n;i++){
      auto check = [&](int j) {
        return i-j+1 <= A[j];
      };
      int ok = i+1, ng = -1;
      while(ok-ng>1){
        int mid = (ok+ng)/2;
        if (check(mid)) ok = mid;
        else ng = mid;
      }
      cout << i-ok+1 << " ";
    }
    cout << "\n";
  }
}
