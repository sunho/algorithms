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
  vector<int> A(n);
  for(int i=0;i<n;i++) {
    cin >> A[i];
  }
  vector<vector<bool>> palin(n, vector<bool>(n));
  for(int i=0;i<n;i++) {
    for(int d=0;d<n;d++) {
      if (i-d < 0 || i+d >= n) {
        break;
      }
      if (A[i-d] != A[i+d]) {
        break;
      }
      palin[i-d][i+d] = true;
    }
    for(int d=0;d<n;d++) {
      if (i-d < 0 || i+1+d >= n) {
        break;
      }
      if (A[i-d] != A[i+1+d]) {
        break;
      }
      palin[i-d][i+1+d] = true;
    }
  }
  int m;
  cin >> m;
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    --a,--b;
    cout << palin[a][b] << "\n"; 
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
