#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i=0;i<n;i++) cin >> A[i];
    bool ok = false;
    for (int i=0;i<n;i++) {
      if (A[i] - 1 <= i)
        ok = true;
    }
    if (ok){
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }  
}
