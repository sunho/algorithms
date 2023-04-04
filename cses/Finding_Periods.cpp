#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> z_function(string s) {
  int n = s.size();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r)
      z[i] = min(z[i-l], r-i+1);
    while (i + z[i] < n && s[i+z[i]] == s[z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i, r = i + z[i] - 1;
    }
  }
  return z;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  string s;
  cin >> s;

  auto z = z_function(s);
  for (int i=0;i<s.size();i++) {
   if (z[i] == s.size()-i) {
    cout << i << " ";
   }
  }
  cout << s.size() << "\n";
}
