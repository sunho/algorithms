#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,q;
  cin >> n >> q;
  vector<int> A(n);
  vector<int> id(n);
  iota(all(A), 0);
  iota(all(id), 0);
  while(q--) {
    int x;
    cin >> x;
    --x;
    int i = id[x];
    if (i == n-1) {
      swap(id[A[i-1]], id[x]);
      swap(A[i], A[i-1]);
    } else {
      swap(id[x], id[A[i+1]]);
      swap(A[i], A[i+1]);
    }
  }
  for(int i=0;i<n;i++){
    cout << A[i] + 1 << " ";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
