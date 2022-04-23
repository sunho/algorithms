#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define _0 first
#define _1 second
template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,k;
  cin >> n >> k;
  vector<array<bool, 26>> S(n);
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    array<bool, 26> b{};
    for(int j=0;j<(int)s.size();j++){
      b[s[j]-'a'] = true;
    }
    S[i] = b;
  }
  int ans = 0;
  for(int mask = 0; mask<(1<<n); mask++) {
    bool ok = true;
    array<int, 26> cnt{};
    for(int i=0;i<n;i++) {
      if (mask & (1<<i)) {
        int kk = 0;
        for(int j=0;j<26;j++){
          if(S[i][j]) cnt[j]++;
        }
      }
    }
    int res = 0;
    for(int i=0;i<26;i++) if (cnt[i] == k) res++;
    ckmax(ans, res);
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
