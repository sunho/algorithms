#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.size();
  vector<int> cnt(26);
  for (int i=0;i<n;i++){
    cnt[s[i]-'A']++;
  }
  string ans;
  int last = -1;
  for (int i=0;i<n;i++){
    int sum = 0;
    int mx = 0, mx_i = -1;
    for (int c=0;c<26;c++){
      if (cnt[c] > mx) {
        mx = cnt[c];
        mx_i = c;
      }
      sum += cnt[c];
    }
    if (mx > sum-mx+1) {
      cout << "-1" << "\n";
      return 0;
    }
    if (mx >= sum - mx + 1) {
      ans.push_back(mx_i + 'A');
      last = mx_i;
      cnt[mx_i]--;
      continue;
    }
    int fi = -1;
    for (int c=0;c<26;c++){
      if (cnt[c] != 0 && last != c) {
        fi = c;
        break;
      }
    }
    ans.push_back(fi+'A');
    last = fi;
    cnt[fi]--;
  }
  cout << ans << "\n";
}
