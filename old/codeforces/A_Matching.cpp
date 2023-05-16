#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int pow10(int n) {
  int res = 1;
  while (n--) res *= 10;
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    const int n = s.size();
    ll ans = 1;
    int num = 0;
    if (s[0] == '0') {
      cout << 0 << "\n";
      continue;
    }
    for (int i=0;i<n;i++){
      if (s[i] == '?') {
        num ++;
        ans *= 10;
      }
    }
    if (s[0] == '?') {
      ans -= pow10(num-1);
    }
    cout << ans << "\n";
  }
}
