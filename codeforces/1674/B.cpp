#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

vector<string> dict;

void solve() {
  string s;
  cin >> s;
  cout << lb(dict, s) + 1 << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  for(char a='a';a<='z';a++) {
    for(char b='a';b<='z';b++){
      if (a == b) continue;
      string t;
      t.push_back(a);
      t.push_back(b);
      dict.push_back(t);
    }
  }
  sort(all(dict));

  int t;
  cin >> t;
  while (t--){
    solve();
  }

  return 0;
}
