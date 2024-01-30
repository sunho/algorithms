#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<int>> nxt(n+1, vector<int>(26, -1));
  for (int i=n-1;i>=0;i--) {
    nxt[i] = nxt[i+1];
    nxt[i][s[i]-'a'] = i+1;
  }
  string sub;
  vector<int> S;
  int cur = 0;
  while (true) {
    bool found = false;
    for (int c = 25; c >= 0; c--) {
      if (nxt[cur][c] != -1) {
        found = true;
        sub.push_back(c+'a');
        S.push_back(nxt[cur][c]-1);
        cur = nxt[cur][c];
        break;
      }
    }
    if (!found) break;
  }
  int m = sub.size();
  int cnt = 0;
  for (int i=0;i<m;i++) {
    if (sub[i] == sub[0]) {
      cnt++;
    }
  }
  sort(begin(sub),end(sub));
  string t;
  int ptr = 0;
  for (int i=0;i<n;i++) {
    if (ptr != sub.size() && S[ptr] == i) {
      t.push_back(sub[ptr]);
      ptr++;
    } else {
      t.push_back(s[i]);
    }
  }
  if (is_sorted(begin(t),end(t))) {
    cout << m - cnt << "\n";
  } else {
    cout << -1 << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
