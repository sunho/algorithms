#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    for (auto& c: s) {
      c = tolower(c);
    }
    if (s == "yes") {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}

