#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,k,m;
  cin >> n >> k >> m;
  string s;
  cin >> s;
  vector<int> cur(k);
  int cur_cnt = 0;
  int cnt = 0;
  string ans;
  for (int i=0;i<m;i++){
    if (!cur[s[i]-'a']) {
      cur[s[i]-'a'] = true;
      cur_cnt++;
    }
    if (cur_cnt == k) {
      ans.push_back(s[i]);
      cnt ++;
      cur_cnt = 0;
      cur.assign(k, false);
    }
  }
  if (cnt < n) {
    cout << "NO" << "\n";
    cout << ans;
    char found = '0';
    for (int i=0;i<k;i++){
      if (!cur[i]) {
        found = (char)('a'+i);
        break;
      }
    }
    for (int i=0;i<n-cnt;i++){
      cout << found;
    }
    cout << "\n";
  } else {
    cout << "YES" << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
