#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, string> M;
    bool ok = true;
    for (int i=0;i<2*n-2;i++) {
      string s;
      cin >> s;
      if (M.count(s.size())) {
        reverse(begin(s), end(s));
        if (s != M[s.size()]) 
          ok = false;
      } else {
        M[s.size()] = s;
      }
    }
    if (ok) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}
