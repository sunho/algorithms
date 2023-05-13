#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  bool ok = false;
  int n;
  string s;
  cin >> n >> s;
  for (int i=0;i<n;i++){
    if (s[i] == 'x') {
      cout << "No";
      return 0;
    }
    if (s[i] == 'o') {
      ok = true;
    }
  }
  if (ok) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}
