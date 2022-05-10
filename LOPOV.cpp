#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,k;
  cin >> n >> k;
  vector<pair<int,int>> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
  }
  sort(all(A));
  vector<int> B(k);
  for(int i=0;i<k;i++){
    cin >> B[i];
  }
  sort(all(B));
  ll ans = 0;
  priority_queue<int> avail;
  for(int i=0,p=0;i<k;i++){
    int b = B[i];
    while (p < n && A[p].first <= b) {
      avail.push(A[p].second);
      p++;
    }
    if (!avail.empty()) {
      ans += avail.top();
      avail.pop();
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
