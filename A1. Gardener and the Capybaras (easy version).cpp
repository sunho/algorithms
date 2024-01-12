#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  for (int i=1;i<=n-1;i++) {
    for (int j=1;j<=n-i;j++){
      string a = s.substr(0, i);
      string b = s.substr(i, j);
      string c = s.substr(i+j);
      if (a <= b && c <= b || b <= a && b <= c) {
        cout << a << " " << b << " " << c <<"\n";
        return;
      }
    }
  }
  cout << ": (" << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
