#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int r,c;
  cin >> r >> c;
  vector<vector<char>> M(15, vector<char>(15));
  for (int i=0;i<15;i++){
    for (int j=0;j<15;j++){
      int dist = max(abs(i-7), abs(j-7));
      if (dist % 2 == 1) {
        M[i][j] = 1;
      }
    }
  }
  --r,--c;
  if (M[r][c]) 
    cout << "black" << "\n";
  else 
    cout << "white" << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
