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
  const int M = 32768;
  int n;
  cin >> n;
  queue<pair<int,int>> q;
  vector<int> dist(M+1, -1);
  q.push({0, 0});
  map<int,vector<int>> invs;
  for(int i=1;i<=M;i++) {
    invs[i*2%M].push_back(i);
  }
  while(!q.empty()){
    auto [d, n] = q.front();
    q.pop();
    if (dist[n] == -1) {
      dist[n] = d;
    } else {
      continue;
    }
    q.push({d+1, (n-1 + M) % M});
    for(int k : invs[n]) {
      q.push({d+1, k});
    }
  }
  for(int i=0;i<n;i++) {
    int a;
    cin >> a;
    cout << dist[a] << " ";
  }
  
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);


  solve();

  return 0;
}
