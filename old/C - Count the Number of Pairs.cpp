#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, int> dd;
    for (int i=0;i<n;i++) {
      dd[s[i]] ++;
    }
    int ans = 0;
    for (char c = 'a'; c <= 'z'; c++) {
      ans += min(dd[c], dd[toupper(c)]);
      int delta = min(k, (max(dd[c], dd[toupper(c)]) - min(dd[c], dd[toupper(c)]))/2);
      ans += delta;
      k -= delta;
    }
    cout << ans << "\n";

  }
}
