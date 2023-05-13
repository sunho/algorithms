#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  map<char,int> cnt;
  for (char c : s) cnt[c]++;
  for (auto [c,k] : cnt) {
    if (k == 1) {
      cout << c;
      return 0;
    }
  }
  cout << -1 << "\n";
}
