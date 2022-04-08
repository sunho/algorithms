#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int maxfreq(vector<int>& a) {
  int res = 0;
  int cur = 0;
  sort(all(a));
  for(int i=0; i < a.size(); i++) {
    if (i == 0 || a[i] == a[i-1]) {
      cur++;
      ckmax(res, cur);
    } else {
      cur = 1;
    }
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  int ans = 0;
  int f = maxfreq(A);
  int ff = f;
  int rem = n - f;
  while (rem > 0) {
    ans++;
    int c = min(rem, ff);
    ans += c;
    rem -= c;
    ff *= 2;
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}
