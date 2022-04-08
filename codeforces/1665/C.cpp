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
  vector<vector<int>> g(n);
  vector<int> outdeg(n);
  for(int i=0;i<n-1;i++){
    int u;
    cin >> u;
    --u;
    outdeg[u]++;
    g[u].push_back(i+1);
  }
  vector<pair<int, int>> deg;
  for(int i=0;i<n;i++) {
    deg.push_back({outdeg[i], i});
  }
  sort(all(deg));
  vector<int> idx;
  for(int i=0;i<n;i++){
    idx.push_back(deg[i].y);
  }
  int t=0;
  vector<int> tt(n);
  for(int i=n-1;i>=0;i--){
    if (outdeg[idx[i]] == 0) {
      continue;
    }
    t++;
    tt[idx[i]] = t;
  }
  t++;
  //cout << t << "\n";
  multiset<int> rem;
  for(int i=0;i<n;i++){
    if (outdeg[i] == 0) continue;
    int c = outdeg[i]-(t-tt[i])-1;
    if (c <= 0) continue;
    rem.insert(c);
  }
  int tk=0;
  while(!rem.empty()) {
    int r = *(--rem.end());
    if (r - tk <= 0) {
      rem.erase(--rem.end());
      continue;
    }
    r--;
    rem.erase(--rem.end());
    rem.insert(r);
    tk++;
    t++;
  }
  
  cout << t << "\n";
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
