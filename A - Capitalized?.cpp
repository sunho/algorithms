#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  if (!isupper(s[0])) {
    cout << "No" << "\n";
    return;
  }
  for (int i=1;i<s.size();i++){
    if (isupper(s[i])) {
      cout << "No";
      return;
    }
  }
  cout << "Yes";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
