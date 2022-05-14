#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void sieves(int PN, vector<int>& lp, vector<int>& pr) {
  lp.assign(PN+1,0);
  for (int i=2; i <= PN; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j=0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= PN; ++j) {
      lp[i * pr[j]] = pr[j];
    }
  }
}

void solve() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  vector<int> lp, pr;
  sieves(1000, lp, pr);
  bool ans = false;
  for(int i=a;i<=b;i++){
    bool ok = true;
    for(int j=c;j<=d;j++){
      if (lp[i+j] == i+j) ok = false;
    }
    ans |= ok;
  }
  if (ans) { 
    cout << "Takahashi" << "\n";
  } else {
    cout << "Aoki" << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
