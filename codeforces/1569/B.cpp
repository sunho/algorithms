#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n;
  cin >> n;
  vector<char> A(n);
  for(int i=0;i<n;i++) cin >> A[i];
  vector<vector<char>> ans(n, vector<char>(n));
  vector<int> one_wins;
  for(int i=0;i<n;i++) {
    if(A[i] == '2') {
      one_wins.push_back(i);
    }
  }
  if(one_wins.size() == 1 || one_wins.size() == 2) {
    cout << "NO" << "\n";
    return;
  }
  for(int i=0;i<one_wins.size();i++) {
    int p = one_wins[i];
    int ne = one_wins[(i+1)%one_wins.size()];
    ans[p][ne] = '+';
    ans[ne][p] = '-';
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      if (i==j) {
        ans[i][j] = 'X';
      } else if (ans[i][j] == 0) {
       ans[i][j] = '=';
      }
    }
  }
  cout << "YES" << "\n";
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout << ans[i][j];
    }
    cout << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}
