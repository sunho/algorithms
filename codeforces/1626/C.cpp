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
  vector<int> k(n);
  vector<int> h(n);
  for(int i=0;i<n;i++){
    cin >> k[i];
  }
  for(int i=0;i<n;i++) {
    cin >> h[i];
  }
  vector<pair<int,int>> ranges;
  for(int i=0;i<n;i++){
    ranges.push_back({k[i] - h[i] + 1, k[i]});
  }
  // for (auto k : ranges) {
  //   cout << k.x << " " << k.y << "\n";
  // }
  ll ans = 0;
  for(int i=0;i<n;i++) {
    pair<int,int> p = ranges.back();
    if (ranges.size() == 1) {
      ll q = (p.y - p.x + 1);
      ans += q*(q+1)/2;
      break;
    }
    pair<int,int> p2 = ranges[ranges.size()-2];
    if (p2.y >= p.x) {
      ranges.pop_back();
      ranges.pop_back();
      pair<int,int> pp = {min(p2.x,p.x), p.y};
      ranges.push_back(pp);
    } else {
      ll q = (p.y - p.x + 1);
      ans += q*(q+1)/2;
      ranges.pop_back();
    }
  }
  cout << ans << "\n";
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
