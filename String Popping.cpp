#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  string S;
  cin >> S;
  int n = S.size();
  auto f = [&](auto&& self, vector<int> s) {
    if (s.size() == 1) {
      return s[0] >= 2;
    }
    if (s.size() == 2) {
      return s[0] >= 2 && s[1] >= 2;
    }
    for (int i=1;i<s.size()-1;i++){
      if (s[i] >= 2) {
        auto t = s;
        t[i-1] += t[i+1];
        t.erase(t.begin()+i,t.begin()+i+2);
        if (self(self, t)) {
          return true;
        }
      }
    }
    return false;
  };
  vector<int> a;
  char cur = '0';
  for (int i=0;i<n;i++){
    if (cur != S[i]) {
      a.push_back(1);
      cur = S[i];
    } else {
      a.back()++;
    }
  }
  cout << f(f, a) << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
