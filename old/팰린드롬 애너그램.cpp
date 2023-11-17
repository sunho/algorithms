#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<char,int> cnt;
  for (int i=0;i<n;i++) {
    if (n%2!=1 || i != n/2) {
      cnt[s[i]]++;
    }
  }
  bool ok = true;
  for (auto [_, c] : cnt) {
    if (c % 2 == 1) {
      ok = false;
    }
  }
  if (ok) {
    cout << "Yes" << "\n";
  } else {
    cout << "No" << "\n";
  }
}
