#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,k,q;
  cin >> n >> k >> q;
  vector<int> board(n, -1);
  vector<int> cord(k);
  for (int i=0;i<k;i++){
    int x;
    cin >> x;
    --x;
    board[x] = i;
    cord[i] = x;
  }
  while(q--){
    int x;
    cin >> x;
    --x;
    if (cord[x] != n-1) {
      if (board[cord[x]+1] == -1) {
        swap(board[cord[x]], board[cord[x]+1]);
        cord[x]++;
      }
    }
  }
  for(int i=0;i<k;i++){
    cout << cord[i] + 1 << " ";
  }
  cout << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
