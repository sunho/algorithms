#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n; 
  vector<long double> A(n);
  for(int i=0;i<n;i++) {
    cin >> A[i];
    A[i] = 1.0l / A[i];
  }
  sort(begin(A), end(A));
  vector<long double> cands;
  for (int i=0;i<3;i++){
    cands.push_back(A[i]);
  }
  for (int i=n-1;i>=max(n-4,3);i--){
    cands.push_back(A[i]);
  }
  long double mn = 1e18;
  long double mx = -1e18;
  int m = cands.size();
  for (int i=0;i<m;i++){
    for (int j=i+1;j<m;j++){
      for (int k=j+1;k<m;k++){
        long double x = cands[i] * cands[j] + cands[i]*cands[k] + cands[j] * cands[k];
        mn = min(mn, x);
        mx = max(mx, x);
      }
    }
  }
  cout << fixed << setprecision(15) << mn << "\n";
  cout << fixed << setprecision(15) << mx << "\n";
}
