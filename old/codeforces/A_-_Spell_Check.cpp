#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (s.size() != 5) {
    cout << "NO\n";
    return;
  }
  set<char> S;
  for (char c : s) 
    S.insert(c);
  if (S.count('T') && S.count('i') && S.count('m') && S.count('u') && S.count('r'))
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;

  while(t--)
    solve();

  return 0;
}
