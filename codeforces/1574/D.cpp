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
  vector<vector<ll>> C(n);
  for(int i=0;i<n;i++){
    int m;
    cin >> m;
    for(int j=0;j<m;j++){
      ll c;
      cin >> c;
      C[i].push_back(c);
    }
  }
  set<array<int, 10>> S;
  int q;
  cin >> q;
  while(q--){
    array<int, 10> b{};
    for (int i=0;i<n;i++) {
      int c;
      cin >> c;
      --c;
      b[i] = c;
    }
    S.insert(b);
  }
  ll maxi = 0;
  array<int, 10> ans{};
  priority_queue<pair<ll,pair<int, array<int, 10>>>> pq;
  array<int,10> last{};
  ll tmp = 0;
  for(int i=0;i<n;i++){
    last[i] = C[i].size()-1;
    tmp += C[i][last[i]];
  }
  pq.push({tmp, {0,last}});
  while (!pq.empty()) {
    auto [l, pp] = pq.top();
    auto [pos, idx] = pp;
    pq.pop();
    if (!S.count(idx)) {
      ans = idx;
      break;
    }
    if (idx[pos] != 0) {
      idx[pos]--;
      pq.push({l+C[pos][idx[pos]]-C[pos][idx[pos]+1], {pos, idx}});
      idx[pos]++;
    }
    if (pos + 1 < n) {
      pq.push({l, {pos+1, idx}});
    }
  }
  for(int i=0;i<n;i++){
    cout << ans[i] + 1 << " ";
  }
}
  
int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  
  solve();
  
  return 0;
}