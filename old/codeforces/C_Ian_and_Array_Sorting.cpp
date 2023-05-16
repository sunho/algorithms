#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    vector<ll> A(n);
    for (int i=0;i<n;i++){
      cin >> A[i];
    }
    auto B = A;
    ll mx = *max_element(begin(A), end(A));
    ll mn = *max_element(begin(A), end(A));
    for (int i=n-1;i>0;i--){
      ll ai = B[i];
      if (B[i] < mx) {
        B[i] += (mx-ai);
        B[i-1] += (mx-ai);
      }
      if (B[i] > mx) {
        B[i] -= (ai-mx);
        B[i-1] -= (ai-mx);
      }
    }
    bool ok = true; 
    for (int i=0;i<n-1;i++){
      if (B[i] > B[i+1]) {
        ok = false;
      }
    }
  
    if (ok) {
      cout << "YES" << "\n";
      continue;
    }
    B = A;
    for (int i=0;i<n-1;i++){
      ll ai = B[i];
      if (B[i] > mn) {
        B[i] -= (ai-mn);
        B[i+1] -= (ai-mn);
      }
      if (B[i] < mn) {
        B[i] += (mn-ai);
        B[i+1] += (mn-ai);
      }
    }
    ok = true; 
    for (int i=0;i<n-1;i++){
      if (B[i] > B[i+1]) {
        ok = false;
      }
    }
    if (ok) {
      cout << "YES" << "\n";
      continue;
    }
    cout << "NO" << "\n";
  }

}
