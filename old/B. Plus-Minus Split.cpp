#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int sum = 0;
  for (int i=0;i<n;i++){
    if (s[i] == '+') {
      sum += 1;
    } else {
      sum -= 1;
    }
  }
  cout << abs(sum) << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
