#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  int n=s.size();
  for (int i=1;i<n-1;i++) {
    if (s[i] == 'a') {
      cout << s.substr(0,i) << " " << 'a' << " " << s.substr(i+1) << "\n";
      return;
    }
  }
  cout << s[0] << " " << s.substr(1,n-2) << " " << s.back() << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
