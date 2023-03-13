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
  for (int i=0;i<n;i++)
    cin >> A[i];
  ll S = 0;
  for(int i=0;i<n-1;i++) {
    S += A[i];
  }
  bool first_nz = false;
  for (int i=0;i<n-1;i++){
    if (!first_nz && A[i] != 0) {
      first_nz = true;
    }
    if (first_nz && A[i] == 0) {
      S++;
    }
  }
  cout << S << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--)
  solve();

  return 0;
}
