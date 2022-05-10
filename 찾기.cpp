#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

vector<int> prefix_function(const string& s, const string& t) {
  int n = (int)s.length();
  vector<int> pi2(n);
  for (int i = 1; i < (int)t.size(); i++) {
    int j = pi2[i-1];
    while (j > 0 && t[i] != t[j])
      j = pi2[j-1];
    if (t[i] == t[j])
      j++;
    pi2[i] = j;
  }
  vector<int> pi(n+1);
  for (int i = 0; i < n; i++) {
    int j = pi[i];
    while (j > 0 && (j == (int)t.size() || s[i] != t[j]))
      j = pi2[j-1];
    if (s[i] == t[j])
      j++;
    pi[i+1] = j;
  }
  return pi;
}

void solve() {
  string s,t;
  getline(cin, s);
  getline(cin, t);
  auto pf = prefix_function(s,t);
  int n = (int)s.size();
  int m = (int)t.size();
  vector<int> ans;
  for(int i=1;i<=n;i++){
    if(pf[i] == m) {
      ans.push_back(i-m+1);
    }
  }
  cout << ans.size() << "\n";
  for(auto a : ans) {
    cout << a << " ";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
