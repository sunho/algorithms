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
  int ans = 1e9;
  for(int i=0;i<n-2;i++) {
    ckmin(ans, 1 + A[i]/2 + A[i+2]/2);
  }
  auto B = A;
  sort(all(B));
  ckmin(ans, (B[0] + 1)/2  + (B[1] + 1)/2);
  for(int i=0;i<n-1;i++) {
    int a = min(A[i], A[i+1]);
    int b = max(A[i], A[i+1]);
    if (b >= a*2) {
      ckmin(ans, (b+1)/2);
    } else {
      ckmin(ans, (a+b+2)/3);
    }
  }
  
  cout << ans << "\n";
}
  
int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  
  solve();
  
  return 0;
}