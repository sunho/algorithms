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
  string S;
  cin >> S;
  int q;
  cin >> q;
  while (q--){
    int k;
    cin >> k;
    ll ans = 0;
    ll cnt = 0;
    ll M = 0;
    ll C = 0;
    for(int i=k-1;i>=0;i--){
      if (S[i] == 'C') {
        C++;
      }
      if (S[i] == 'M') {
        M++;
        cnt += C;
      }
    }
    for (int i=0;i<n;i++){
      if(S[i] == 'D'){
        ans += cnt;
      }
      if (S[i] == 'M') {
        M--;
        cnt -= C;
      }
      if (S[i] == 'C') {
        C--;
      }
      if (i+k < n) {
        if (S[i+k] == 'M') {
          M++;
        }
        if (S[i+k] == 'C'){
          C++;
          cnt += M;
        }
      }
    }
    cout << ans << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
