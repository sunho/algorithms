#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> mp(n);
  vector<int> stk;
  for (int i=0;i<n;i++){
    if (s[i] == '(') {
      stk.push_back(i);
    } else if (s[i] == ')'){
      mp[stk.back()] = i;
      mp[i] = stk.back();
      stk.pop_back();
    }
  }

  auto f = [&](auto&& self, int sl, int sr) -> tuple<int,int,int> {
    if (sl == sr) {
      return {0,0,1};
    }
    auto R = s[sr-1] == '?' ? self(self,sr-1,sr-1) : self(self,mp[sr-1]-3,sr-1);
    auto L = s[sl+4] == '?' ? self(self,sl+4,sl+4) : self(self,sl+4,mp[sl+7]);
    auto [l1,r1,n1] = L;
    auto [l2,r2,n2] = R;
    int n = n1+n2;
    if (s.substr(sl,3) == "min") {
      return {min(l1,l2),l1+l2+r1-l1+r2-l2,n};
    } else {
      int rr1 = n1-r1-1;
      int rr2 = n2-r2-1;
      return {n-1-(rr1+rr2+r2-l2+r1-l1), n-1-min(rr1,rr2), n};
    }
  };
  auto [l,r,_] = f(f,0,n-1);
  cout << r-l+1 << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
