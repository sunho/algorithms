#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  for (int i=1;i<=n;i++){
    if (i >= 5) {
      ll nn = (ll)(i*i);
      ll ans = nn*(nn-1)/2;
      ans -= 4*(2+3+3+4)/2;
      ans -= 4*4*(i-4)/2;
      ans -= 6*4*(i-4)/2;
      ans -= 8*(i-4)*(i-4)/2;
      cout << ans << "\n";
    } else {
      int ans_table[] = {0,6,28,96,252};
      cout << ans_table[i-1] << "\n";
    }
  }

}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
