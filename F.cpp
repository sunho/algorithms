#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,m,k;
  cin >> n >> m >> k;
  vector<vector<char>> A(n, vector<char>(m));
  map<char, vector<pair<int,int>>> M;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> A[i][j];
      M[A[i][j]].push_back({i,j});
    }
  }
  string s;
  cin >> s;
  vector<char> ans;
  pair<int,int> P = {0,0};
  auto find_path = [&](pair<int,int> e) {
    while(P.first != e.first) {
      if (P.first < e.first) {
        P.first++;
        ans.push_back('D');
      } else {
        P.first--;
        ans.push_back('U');
      }
    }
    while(P.second != e.second) {
      if (P.second < e.second) {
        P.second++;
        ans.push_back('R');
      } else {
        P.second--;
        ans.push_back('L');
      }
    }
  };

  int L = 0;
  while(true) {
    bool ok = true;
    vector<pair<int,int>> cand;
    for(int i=0;i<s.size();i++){
      char c = s[i];
      if (M[c].empty()) {
        ok = false;
        break;
      }
      cand.push_back(M[c].back());
      M[c].pop_back();
    }
    if (!ok) {
      break;
    }
    L++;
    for(auto x : cand) {
      find_path(x);
      ans.push_back('P');
    }
  }
  find_path({n-1,m-1});
  cout << L << " " << ans.size() << "\n";
  for(auto x : ans) {
    cout << x;
  }
  cout << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
