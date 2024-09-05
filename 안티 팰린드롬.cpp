#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  sort(begin(s),end(s));
  map<char,int> cnt;
  int mx = 0;
  for (char c : s) {
    cnt[c]++;
    mx = max(mx, cnt[c]);
  }
  int n = (int)s.size();
  if (mx > (n+1)/2) {
    cout << -1;
    return;
  }
  vector<char> ans(n);
  for (int i=0;i<(n+1)/2;i++) {
    ans[i] = s[i];
    cnt[s[i]]--;
  }
  auto get_c = [&](char cc) {
    for (auto it = cnt.begin(); it != cnt.end(); ++it) {
      if (it->first == cc) {
        continue;
      }
      if (it->second) {
        return it->first;
      }
    }
    return 'x';
  };
  for (int i=(n+1)/2;i<n;i++){
    char c = get_c(ans[n-i-1]);
    cnt[c]--;
    ans[i] = c;
  }
  for (char c : ans) {
    cout << c;
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
