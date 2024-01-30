#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> A(n);
  set<char> vowels = {'a','e'};
  for (int i=0;i<n;i++){
    if (vowels.count(s[i])) {
      A[i] = 0;
    } else {
      A[i] = 1;
    }
  }
  vector<string> ans;
  int cur = n-1;
  while (cur > 0) {
    if (A[cur] == 1) {
      ans.push_back(s.substr(cur-2,3));
      cur -= 3;
    } else {
      ans.push_back(s.substr(cur-1,2));
      cur -= 2;
    }
  }
  reverse(begin(ans),end(ans));
  for (int i=0;i<ans.size();i++){
    cout << ans[i];
    if (i != ans.size()-1) {
      cout << ".";
    }
  }
  cout << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
