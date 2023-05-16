#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
using ll = long long;

void solve() {
  ll x;
  cin >> x;
  string s = to_string(x);
  int n = s.size();
  auto pow10 = [](int n) -> ll {
    ll i = 1;
    while (n--)
      i *= 10;
    return i;
  };
  auto repeat = [&](string t) {
    string res;
    while (res.size() != n) {
      res += t;
    }
    return res;
  };
  string ans = to_string(pow10(s.size()-1)-1);
  auto calc = [&]() {
    for (int k=1;k<n;k++){
      if (n % k != 0) continue;
      string cand;
      for (int i=0;i<k;i++){
        cand.push_back(s[i]);
      }
      string cand2 = to_string(stoll(cand)-1);
      if (n % cand2.size() == 0) {
        if (stoll(ans) < stoll(repeat(cand2)) && stoll(repeat(cand2)) <= x) {
          ans = repeat(cand2);
        }
      }
      if (stoll(ans) < stoll(repeat(cand)) && stoll(repeat(cand)) <= x) {
        ans = repeat(cand);
      }
      
    }
  };
  calc();
  if (s[0] != '1') {
    s[0]--;
    for (int i=1;i<n;i++){
      s[i] = '9';
    }
    calc();
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--)
    solve();
}
