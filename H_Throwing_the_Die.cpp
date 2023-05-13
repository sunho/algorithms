#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  array<long double, 6> dp{0};
  for (int i=0;i<n;i++){
    long double total=0;
    for (int j=0;j<6;j++){
      total += dp[j]/6.0l;
    }
    array<long double, 6> next{0};
    for (int j=0;j<6;j++){
      if (j+1 > total) {
        next[j] = j+1;
      } else {
        next[j] = total;
      }
    }
    dp = next;
  }
  long double ans = 0;
  for (int i=0;i<6;i++){
    ans += dp[i]/6.0l;
  }
  cout << fixed << setprecision(10) << ans << "\n";
}
