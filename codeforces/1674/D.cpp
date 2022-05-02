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
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  auto B = A;
  sort(all(B));
  int s = n % 2 == 0 ? 0 : 1;
  for(int i=n-1;i>=s;i-=2){
    if (A[i-1] > A[i]) {
      swap(A[i-1], A[i]);
    }
  }
  if (A == B) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
  
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
