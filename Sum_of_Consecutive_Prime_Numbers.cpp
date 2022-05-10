#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  const int PN = 4e6;
  vector<int> lp(PN+1);
  vector<int> pr;
  for (int i=2; i <= PN; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j=0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= PN; ++j) {
      lp[i * pr[j]] = pr[j];
    }
  }
  int n;
  cin >> n;
  int ans = 0;
  ll sum = 0;
  for(int i=0,p=0;i<(int)pr.size();i++){
    while(p < (int)pr.size() && sum < n) {
      sum += pr[p];
      p++;
    } 
    while (p > i && sum - pr[p-1] > n) {
      sum -= pr[p-1];
      p--;
    }
    if (sum == n) {
      ans++;
    }
    if (p > i) sum -= pr[i];
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
