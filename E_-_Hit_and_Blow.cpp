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
  vector<int> A(n), B(n);
  for(int i=0;i<n;i++) cin >> A[i];
  for(int i=0;i<n;i++) cin >> B[i];
  int d_cnt = 0;
  for(int i=0;i<n;i++) {
    if (A[i] == B[i]) {
      d_cnt++;
    }
  }
  int s_cnt = 0;
  set<int> S;
  for(int i=0;i<n;i++){
    S.insert(B[i]);
  }
  for(int i=0;i<n;i++) {
    if (S.count(A[i])) s_cnt++;
  }
  cout << d_cnt << "\n" << s_cnt - d_cnt << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
