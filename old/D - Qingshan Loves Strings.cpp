#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    string e;
    cin >> e;
    bool ok = true;
    bool all_1 = true, all_0 = true;
    for (int i=0;i<n-1;i++){
      if (s[i] == s[i+1]) {
        ok = false;
        if (s[i] == '0') {
          all_1 = false;
        } else {
          all_0 = false;
        }
      }
    }
    bool ok2 = true;
    for (int i=0;i<m-1;i++) {
      if (e[i] == e[i+1]) {
        ok2 = false;
      }
    }
    if (ok) {
      cout << "Yes" << "\n";
      continue;
    }
    if (!ok && e.back() != e[0]) {
      cout << "No" << "\n";
      continue;
    }
    if (ok2 && all_0 && e.back() == '1') {
      cout << "Yes" << "\n";
      continue;
    }
    if (ok2 && all_1 && e.back() == '0') {
      cout << "Yes" << "\n";
      continue;
    }
    cout << "No" << "\n";
  }
}
