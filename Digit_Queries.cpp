#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  ll k;
  cin >> k;
  --k;
  ll cur = 1;
  ll len = 1;
  // x >= a*b
  // floor(x/b) >= a
  while (k / (9*len) >= cur) {
    k -= (cur*10-cur)*len;
    cur *= 10;
    len ++;
  }
  ll num = cur + k / len;
  string s = to_string(num);
  cout << s[k%len] << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
