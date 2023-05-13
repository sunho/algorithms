#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using ld = long double;


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> R(n);
  for (int i=0;i<n;i++) cin >> R[i];
  ld ans = 0;
  for (int i=0;i<n;i++) {
    for (int j=0;j<R[i];j++){
      for (int k=0;k<i;k++){
        ans += (ld)max(R[k] - j - 1,0) / (R[i]*R[k]);
      }
    }
  }
  cout << fixed << setprecision(6) <<  ans << "\n";
}
