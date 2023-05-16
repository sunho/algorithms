#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    map<char, int> cnt;
    for (char c : s) {
      cnt[c]++;
    }
    int x = 0;
    for (auto [_, c] : cnt) {
      if (c%2 == 0) {
        x++;
      }
    }
    
  }
}
