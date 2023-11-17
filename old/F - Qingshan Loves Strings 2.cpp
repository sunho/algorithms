#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string k;
  cin >> k;
  int black = 0, white = 0;
  for (int i=0;i<n;i++) {
    if (k[i] == '0') black++;
    if (k[i] == '1') white++;
  }
  if (black != white) {
    cout << -1 << "\n";
    return;
  }
  deque<char> S;
  for (char c : k) {
    S.push_back(c);
  }
  vector<int> ans;
  int l = 0, r = n;
  while (S.size()) {
    if (S.front() != S.back()) {
      S.pop_front();
      S.pop_back();
      l++, r--;
    } else {
      if (S.front() == '0') {
        ans.push_back(r);
        l++,r++;
        S.pop_front();
        S.push_back('0');
      } else {
        ans.push_back(l);
        l++,r++;
        S.pop_back();
        S.push_front('1');
      }
    }
  }
  cout << ans.size() << "\n";
  for (int k : ans) {
    cout << k << " ";
  }
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
