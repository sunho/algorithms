#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  string A[3];
  cin >> A[0] >> A[1] >> A[2];
  const int n = A[0].size();
  auto calc_diff = [&](string a, string b) {
    vector<bool> res(n);
    for (int s=0;s<n;s++){
      bool ok = true;
      for (int i=0;i<n;i++){
        ok &= (a[i] != b[(i+s)%n]);
      }
      res[s] = ok;
    }
    return res;
  };
  vector diff(3, vector(3, vector<bool>()));
  for (int i=0;i<3;i++){
    for (int j=i+1;j<3;j++){
      diff[i][j] = calc_diff(A[i], A[j]);
    }
  }
  const int inf = 1e9;
  int ans = inf;
  auto f = [&](int k) {return min(k, n-k); };
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if (diff[0][1][i] && diff[0][2][j] && diff[1][2][(j-i+n)%n]) {
        ans = min({ans, f(i) + f(abs(j-i)), f(j) + f(abs(j-i)), f(i) + f(j)});
      }
    }
  }
  if (ans == inf) cout << -1 << "\n";
  else cout << ans << "\n";
}
