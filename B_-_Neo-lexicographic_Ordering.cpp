#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  string s;
  cin >> s;
  vector<int> inv(26);
  for(int i=0;i<26;i++){
    inv[(int)(s[i]-'a')]=i;
  }
  int n;
  cin >> n;
  vector<string> A(n);
  vector<int> ord(n);
  vector<vector<int>> seq(n);
  iota(all(ord), 0);
  for(int i=0;i<n;i++){
    cin >> A[i];
    for(int j=0;j<(int)A[i].size();j++){
      seq[i].push_back(inv[(int)(A[i][j]-'a')]);
    }
  }
  sort(all(ord), [&](int a, int b) {
    return seq[a] < seq[b];
  });
  for(int i=0;i<n;i++){
    cout << A[ord[i]] << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
