#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  string s;
  cin >> s;
  string t;
  cin >> t;
  int n = s.size();
  int m = t.size();
  string st = t + "$" + s;
  vector<int> pi(st.size());
  for (int i=1;i<st.size();i++){
    int j = pi[i-1];
    while (j > 0 && st[j] != st[i]) 
      j = pi[j-1];
    if (st[j] == st[i]) 
      j++;
    pi[i] = j;
  }
  int ans = 0;
  for (int i=m;i<st.size();i++){
    if (pi[i] == m) {
      ans++;
    }
  }
  cout << ans << "\n";
}
