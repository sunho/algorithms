#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  for (int i=0;i<s.size()-1;i++){
    if (s[0] != '0' && s[i+1] != '0') {
      int a =stoi(s.substr(0,i+1));
      int b =stoi(s.substr(i+1));
      if (a < b) {
        cout << a << " " << b << "\n";
        return;
      }
    }
  }
  cout << -1 << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
