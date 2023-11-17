#include <bits/stdc++.h>

using namespace std;

void solve() {
  int k;
  cin >> k;
  string s;
  cin >> s;
  reverse(begin(s),end(s));
  for (int i=0;i<s.size();i++) {
    s[i] = s[i] == ')' ? '(' : ')';
  }
  vector<int> inv(s.size());
  stack<int> pos;
  int lvl = 0;
  for (int i=0;i<s.size();i++){
    if (s[i] == '(')  {
      pos.push(i);
    }
    else {
      inv[pos.top()] = i;
      inv[i] = pos.top();
      pos.pop();
    }
  }
  vector<int> pf(s.size()+1);
  for (int i=0;i<s.size();i++){
    pf[i+1] = pf[i] + (s[i] == ')');
  }
  vector<int> vals;
  for (int i=0;i<s.size();i++){
    if (s[i] == '(') {
      vals.push_back(pf[inv[i]]-pf[i]);
    }
  }
  sort(rbegin(vals),rend(vals));
  long long ans = 0;
  for (int i=min(k,(int)vals.size()-1);i<vals.size();i++){
    ans += vals[i];
  }
  cout << ans << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
