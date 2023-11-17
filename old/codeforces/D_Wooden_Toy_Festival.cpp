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
    vector<int> A(n);
    for (int i=0;i<n;i++) cin >> A[i];
    sort(begin(A),end(A));
    A.resize(unique(begin(A),end(A))-begin(A));
    n = A.size();
    auto check = [&](ll diff) {
      int l = 0;
      while (l<n){
        if ((A[l]-A[0]+1)/2 <= diff) {
          l++;
        } else {
          break;
        }
      }
      int r = l;
      while (r<n) {
        if ((A[r]-A[l]+1)/2 <= diff) {
          r++;
        } else {
          break;
        }
      }
      if (l == n || r == n) return true;
      return (A[n-1]-A[r]+1)/2<=diff;
    };
    ll ng=-1,ok=4e9;
    while (ok-ng>1) {
      ll mid = (ok+ng)/2;
      if (check(mid)) ok = mid;
      else ng = mid;
    }
    cout << ok << "\n";
  }
} 
