#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

string repeat(int x, int n) {
  return string(n, (char)('0'+x));
}

void solve() {
  ll l, r;
  cin >> l >> r;
  if (l == r) {
    cout << l << "\n";
    return;
  }
  string L = to_string(l);
  string R = to_string(r);
  while (L.size() != R.size()) {
    L = "0" + L;
  }
  int n = L.size();
  string common;
  for (int i=0;i<n;i++) {
    if (L[i] != R[i]) {
      common = L.substr(0,i);
      L = L.substr(i);
      R = R.substr(i);
      break;
    }
  }
  n = L.size();
  vector<string> cands;
  cands.push_back(common + L);
  cands.push_back(common + R);
  if (R[0] - L[0] >= 2) 
    for (int i=L[0]-'0'+1;i<=R[0]-'0'-1;i++) {
      cands.push_back(common + repeat(i,n));
    }
  for (int i=1;i<n;i++){
    for (int d=L[i]-'0'+1;d<=9;d++){
      cands.push_back(common + L.substr(0, i) + repeat(d,n-i));
    }
  }
  for (int i=1;i<n;i++){
    for (int d=R[i]-'0'-1;d>=0;d--){
      cands.push_back(common + R.substr(0, i) + repeat(d,n-i));
    }
  }
  pair<int, string> ans = {10, ""};
  for (string cand : cands) {
    cand = to_string(stoll(cand));
    int score = *max_element(begin(cand),end(cand)) - *min_element(begin(cand),end(cand));
    ans = min(ans, {score, cand});
  }
  cout << ans.second << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
