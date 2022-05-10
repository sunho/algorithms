#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;

void solve() {
  string s;
  cin >> s;
  int f = 0;
  for(int i=0;i<(int)s.size();i++){
    if (s[i] == 'a') f++;
    else break;
  }
  int b = 0;
  while (!s.empty() && s.back() == 'a') {
    s.pop_back();
    b++;
  }
  if (f > b) {
    cout << "No" << "\n";
    return;
  }
  if ((int)s.size() >= f) {
    s=s.substr(f);
  }
  auto t = s;
  reverse(all(t));
  if (s == t) cout << "Yes" << "\n";
  else cout << "No" << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
