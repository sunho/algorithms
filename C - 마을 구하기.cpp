#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// none
// DD...
// AA....DD
// only one
// AAaBCD...
// ACD...bBB
// else
// AAaBCD...
// AACCDDbbbcCCccc...

void solve() {
  int n;
  cin >> n;
  char c;
  cin >> c;
  string s;
  cin >> s;
  map<char,int> cnt;
  char mn = 'Z';
  for (int i=0;i<n;i++){
    if (s[i] >= 'A' && s[i] <= 'Z')
      mn = min(mn,s[i]);
    cnt[s[i]]++;
  }
  auto print_rest = [&](bool uy) {
    for (auto [c, cc] : cnt) {
      if (uy && islower(c)) continue;
      for (int i=0;i<cc;i++){
        cout << c;
      }
    }
  };
  if (cnt[tolower(c)] <= 1) {
    if (mn == c) {
      for (int i=0;i<cnt[c];i++)
        cout << c;
      cnt[c] = 0;
      if (cnt[tolower(c)]) {
        cout << (char)tolower(c);
      }
      cnt[tolower(c)] = 0;
      print_rest(false);
    } else {
      int cc = cnt[c];
      bool cc2 = cnt[tolower(c)];
      cnt[c] = 0;
      cnt[tolower(c)] = 0;
      print_rest(false);
      if (cc2) {
        cout << (char)tolower(c);
      }
      for (int i=0;i<cc;i++)
        cout << c;
    }
  } else {
    if (mn == c) {
      for (int i=0;i<cnt[c];i++)
        cout << c;
      cnt[c] = 0;
      cout << (char)tolower(c);
      cnt[tolower(c)]--;
      print_rest(false);
    } else {
      for (auto [k, cc] : cnt) {
        if (islower(k) || c == k) continue;
        for (int i=0;i<cc;i++){
          cout << k;
        }
      }
      for (auto [k, cc] : cnt) {
        if (isupper(k)) continue;
        if (k == tolower(c)) {
          cout << k;
          for (int i=0;i<cnt[c];i++){
            cout << c;
          }
          for (int i=0;i<cc-1;i++){
            cout << k;
          }
        } else {
          for (int i=0;i<cc;i++){
            cout << k;
          }
        }
      }
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
