#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,max_a,min_a;
  cin >> n >> max_a >> min_a;
  vector<int> A(n);
  for(int i=0;i<n;i++) cin >> A[i];
  ll ans = 0;
  int last_mini = -1;
  int last_maxi = -1;
  int last_xx = -1;
  int mini = 1e9 + 1;
  int maxi = 0;
  for(int r=0;r<n;r++){
    if (last_xx == -1) {
      last_xx = r;
    }
    mini = min(mini, A[r]);
    maxi = max(maxi, A[r]);
    if (A[r] == min_a) {
      last_mini = r;
    }
    if (A[r] == max_a) {
      last_maxi = r;
    }
    if (maxi > max_a || mini < min_a) {
      last_xx = -1;
      mini = 1e9 + 1;
      maxi = 0;
    }
    if(mini == min_a && maxi == max_a) {
      ans += min(last_mini, last_maxi) - last_xx + 1;
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
