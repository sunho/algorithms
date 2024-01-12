#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> prefix_function(const string& s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i-1];
    while (j > 0 && s[i] != s[j])
      j = pi[j-1];
    if (s[i] == s[j])
      j++;
    pi[i] = j;
  }
  return pi;
}

string reversed(const string& s) {
  string res = s;
  reverse(begin(res),end(res));
  return res;
}

void solve() {
  string s,t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  auto go = [&](const string& s, const string& t) {
    tuple<int,int,int> ans = {0,0,0};
    for (int ptr=0;ptr<=m;ptr++) {
      auto pf1 = prefix_function(t.substr(ptr) + "$" + s);
      auto pf2 = prefix_function(reversed(t.substr(0,ptr)) + "$" + reversed(s));
      pf1.push_back(0), pf2.push_back(0);
      for (int i=0;i<=n;i++) {
        int l = pf1[i-1+m-ptr+1];
        int r = pf2[n-i-1+ptr+1];
        if (r+l == 0) continue;
        ans = max(ans, {l+r, i-l, ptr-r});
      }
    }
    return ans;
  };
  auto ans = go(s,t);
  reverse(begin(t),end(t));
  auto ans2 = go(s,t);
  if (get<0>(ans) < get<0>(ans2)) {
    auto [k,i,j] = ans2;
    ans = {k,i,m-1-j-k+1};
  }
  auto [k,i,j] = ans;
  cout << k << "\n";
  cout << i << " " << j << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
