#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  string s;
  cin >> n >> s;
  array<int, 26> cnt{};
  char mn = 'z';
  int mx = 0;
  for (int i=0;i<s.size();i++) {
    if (mn > s[i]) {
      mn = s[i];
      mx = i;
    } else if (mn == s[i]) {
      mx = i;
    }
    cnt[s[i]-'a'] ++;
  }
  for (int i=0;i<n;i++){
    cnt[s[i]-'a']--;
    if (s[i] > mn && cnt[mn-'a'] > 0) {
      cout << mn << s.substr(0,mx) << s.substr(mx+1) << "\n";
      return;
    }
  }
  cout << s << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
