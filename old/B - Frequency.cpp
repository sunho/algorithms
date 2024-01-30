#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  map<char,int> cnt;
  for (char c : s) {
    cnt[c]++;
  }
  pair<int,char> mx = {};
  for (auto [a, c] : cnt) {
    mx = max(mx, {c,-a});
  }
  cout << (char)-mx.second << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
