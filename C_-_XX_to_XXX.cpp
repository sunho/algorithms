#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  string s,t;
  cin >> s >> t;
  vector<pair<char, int>> S, T;
  while(!s.empty()) {
    if (S.empty() || S.back().first != s.back()) {
      S.push_back({s.back(), 1});
    } else {
      S.back().second++;
    }
    s.pop_back();
  }
  while(!t.empty()) {
    if (T.empty() || T.back().first != t.back()) {
      T.push_back({t.back(), 1});
    } else {
      T.back().second++;
    }
    t.pop_back();
  }
  if (S.size() != T.size()) {
    cout << "No" << "\n";
    return;
  }
  for (int i=0;i<S.size();i++){
    if (S[i].first != T[i].first) {
      cout << "No" << "\n";
      return;
    }
    if (S[i].second > T[i].second || (S[i].second != T[i].second && S[i].second == 1)) {
      cout << "No" << "\n";
      return;
    }
  }
  cout << "Yes" << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
