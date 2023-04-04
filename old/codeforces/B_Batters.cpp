#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  array<int,4> board{};
  int n;
  cin >> n;
  int p = 0;
  for (int i=0;i<n;i++){
    int k;
    cin >> k;
    board[0]++;
    for (int j=3;j>=0;j--) {
      if (j + k >= 4) {
        p += board[j];
        board[j] = 0;
      } else {
        board[j+k] += board[j];
        board[j] = 0;
      }
    }
  }
  cout << p << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
