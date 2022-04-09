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
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i=0;i<n;i++) {
    cin >> A[i];
  }
  sort(all(A));
  // cout << "\n";
  const ll inf = 1e18;
  ll gans = inf;
  auto go = [&](ll days, int prt) -> bool {
    vector<ll> rem(3);
    rem[1] = days/2 + (days&1);
    rem[2] = days/2;
    int mf = A.back();
    if ((mf & 1) != prt) {
      mf++;
    }
    for(int i=0;i<n;i++) {
      ll d = mf-A[i];
      if ((A[i]&1) != prt) {
        ll k = min(rem[1], 1ll);
        rem[1] -= k;
        d -= k;
      }
      if (rem[2] > 0) {
        ll k = min(rem[2], d/2);
        rem[2] -= k;
        d -= 2*k;
      } 
      if (rem[1] > 0) {
        ll k = min(rem[1], d);
        rem[1] -= k;
        d -= k;
      }
      if (d > 0) {
        // cout << "ddd" << "\n";
        return false;
      }
    }
    return true;
  };
  ll l = -1, r = 1e18+1;
  while(r-l>1) {
    ll mid = (r+l)/2;
    if (go(mid, 0) || go(mid, 1)) r = mid;
    else l = mid;
  };
  cout << r << "\n";
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
