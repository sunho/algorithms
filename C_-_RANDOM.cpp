#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> S(h, vector<char>(w)), T(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> S[i][j];
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> T[i][j];
    }
  }
  vector<string> Ss(w), Tt(w);
  for (int i = 0; i < w; i++) {
    string s, t;
    for (int j = 0; j < h; j++) {
      s.push_back(S[j][i]);
      t.push_back(T[j][i]);
    }
    Ss[i] = s;
    Tt[i] = t;
  }
  sort(all(Ss));
  sort(all(Tt));

  if (Ss != Tt) {
    cout << "No" << "\n";
  } else {
    cout << "Yes" << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
