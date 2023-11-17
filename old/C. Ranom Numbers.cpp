#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  map<char,int> M({{'A',1},{'B',10},{'C',100},{'D',1000},{'E',10000}});
  vector<ll> factors = {1,10,100,1000,10000};
  vector<vector<int>> vals(5);
  for (int i=0;i<n;i++){
    vals[s[i]-'A'].push_back(i);
  }
  auto check = [&](char c, int i) {
    for (char k=c+1;k<='E';k++) {
      if (lower_bound(begin(vals[k-'A']), end(vals[k-'A']), i) != vals[k-'A'].end()) {
        return false;
      }
    }
    return true;
  };
  vector<ll> pf(n+1);
  for (int i=n-1;i>=0;i--) {
    if (check(s[i], i+1)) {
      pf[i] = pf[i+1] + M[s[i]];
    } else {
      pf[i] = pf[i+1] - M[s[i]];
    }
  }
  vector<int> cnt(5);
  ll ans = pf[0];
  ll sum = 0;
  for (int i=0;i<n;i++){
    auto cnt2 = cnt;
    ll sum2 = sum;
    for(int k=0;k<5;k++){
      sum2 -= cnt2[k] * factors[k];
    }
    for (char k='A';k<='E';k++){
      if (!check(k,i+1)) {
        cnt2[k-'A'] = 0;
      }
    }
    for (int k=4;k>=0;k--){
      ll cand = 0;
      sum2 += 2 * cnt2[k] * factors[k];
      if (check('A'+k,i+1))
        cand = factors[k] + sum2;
      else
        cand = -factors[k] + sum2;
      ans = max(ans, cand + pf[i+1]);
    }
    for (int k=s[i]-'A'-1;k>=0;k--){
      sum -= cnt[k]*factors[k];
      cnt[k] = 0;
    }
    cnt[s[i]-'A']++;
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
