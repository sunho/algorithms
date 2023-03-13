#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,m;
  cin >> n >> m;
  vector<int> F(n), B(n);
  vector<int> A(m);
  iota(all(F), 0);
  iota(all(B), 0);
  for(int i=0;i<m;i++){
    cin >> A[i];
    A[i]--;
  }
  int j = 0;
  
  // (0) 
  for(int i=0;i<m;i++) {

  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
