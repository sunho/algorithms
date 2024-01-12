#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  stack<int> sz;
  sz.push(0);
  for (int i=0;i<s.size();i++){
    if (s[i] == '(') {
      if (!sz.empty() && sz.top() >= 1) {
        cout << "+";
      }
      cout << "(";
      sz.push(0);
    } else {
      if (sz.top() == 0) {
        cout << "1";
      }
      sz.pop();
      if (!sz.empty()) {
        sz.top()++;
      }
      cout << ")";
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
