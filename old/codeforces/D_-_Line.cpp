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
  string s;
  cin >> s;
  vector<int> score(n);
  for (int i=0;i<s.size();i++) {
    if (s[i] == 'L')
      score[i] = i;
    else
      score[i] = n-i-1;
  }
  sort(all(score));
  ll sum = 0;
  for(int i=0;i<n;i++){
    sum += score[i];
  }
  for (int i=0;i<n;i++){
    sum -= score[i];
    sum += max(score[i], n-1-score[i]);
    cout << sum << " ";
  }
  cout << "\n";
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
