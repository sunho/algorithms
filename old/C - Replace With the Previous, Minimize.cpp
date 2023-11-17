#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    A[i] = s[i] - 'a';
  }
  int dec = n;
  int mx = 0;
  for (int i=0;i<n;i++){
    if (A[i] > k) {
      dec = i;
      break;
    } else {
      mx = max(mx, A[i]);
    }
  }
  int rem = k - mx;
  int dd = dec == n ? 0 : A[dec] - rem;
  int dd2 = dec == n ? 0 : A[dec];
  for (int i=0;i<n;i++){
    if (A[i] <= mx) {
      A[i] = 0;
    } else {
      if (A[i] <= dd2 && A[i] > dd) {
        A[i] = dd;
      }
    }
  }
  for (int i=0;i<n;i++){
    cout << (char)(A[i] + 'a');
  }
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}
