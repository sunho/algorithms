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
  vector<pair<string,string>> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
  }
  multiset<string> S;
  for (auto [x,y] : A){
    S.insert(x);
    S.insert(y);
  }
  bool ok = true;
  for (auto [x,y] : A){
    S.erase(S.lower_bound(x));
    S.erase(S.lower_bound(y));
    if (S.find(x) != S.end() && S.find(y) != S.end()) {
      ok = false;
    }
    S.insert(x);
    S.insert(y);
  }
  if (ok) cout << "Yes" << "\n";
  else cout << "No" << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
