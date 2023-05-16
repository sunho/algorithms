#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
  string s;
  cin >> s;

  ll ans = 0;
  int n = s.size();
  int cur = 0;
  for (int i=0;i<2*n;i++){
    if (cur == n) {
      return (ll)n*n;
    }
    if (s[i%n] == '0') {
      ll res = 0;
      for (int j=0;j<cur;j++) {
        res = max(res, (ll)(cur-j)*(j+1));
      }
      ans = max(ans, res);
      cur = 0;
    } else {
      cur++;
    }
  }
  return ans;
}


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--)
    cout << solve() << "\n";
}
