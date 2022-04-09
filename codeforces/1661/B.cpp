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
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    int gans = 1e9;
    if (a == 0) {
      cout << 0 << " ";
    } else {
      const int M = 32768;
      vector<pair<int,int>> cands;
      for(int i=0;i<16;i++){
        cands.push_back({a+i,i});
      }
      for(auto [cand,c] : cands) {
        int ans = c;
        cand %= M;
        while (cand != 0) {
          cand <<= 1;
          cand %= M;
          ans++;
        }
        gans = min(gans, ans);
      }
      cout << gans << " ";
    }
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);


  solve();

  return 0;
}
