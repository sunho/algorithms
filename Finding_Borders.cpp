#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> prefix_function(string s) {
  int n = s.size();
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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  string s;
  cin >> s;

  auto pi = prefix_function(s);
  int cur = pi[s.size()-1];
  vector<int> ans;
  while (cur > 0) {
    ans.push_back(cur);
    cur = pi[cur-1];
  }
  reverse(begin(ans), end(ans));
  for (int i=0;i<ans.size();i++){
    cout << ans[i] << " ";
  }
}
