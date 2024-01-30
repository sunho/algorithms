#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  string s;
  cin >> n >> s;
  int zero = 0;
  for (int i=0;i<n-1;i++){
    if (s[i] != s[i+1]) {
      cout << "YES" << "\n";
      return;
    }
  }
  for (int i=0;i<n;i++){
    if (s[i] == '0'){
      zero++;
    }
  }
  if (zero > n-zero) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
