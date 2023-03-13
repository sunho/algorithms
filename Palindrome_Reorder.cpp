#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int cnt[26] = {};
  for (char c : s) {
    cnt[c-'A']++;
  }
  char rem = 0;
  string ans;
  for (int i=0;i<26;i++) {
    if (cnt[i] % 2) {
      if (rem != 0 || n % 2 == 0) {
        cout << "NO SOLUTION" << "\n";
        return;
      }
      rem = i+'A';
    }
    for (int j=0;j<cnt[i]/2;j++) {
      ans.push_back(i+'A');
    }
  }
  cout << ans;
  if (rem) cout << rem;
  reverse(begin(ans), end(ans));
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
