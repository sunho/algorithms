#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifndef ONLINE_JUDGE
#include "lib/debug.h"
#define dbg(...) std::cerr << __DEBUG_UTIL__::outer << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif


void solve() {
  int n, x;
  cin >> n >> x;
  map<int,int> A;
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    A[i] = a;
  }
  dbg(A);
  vector<set<int>> bts(30);
  for (int i=0;i<n;i++){
    for (int x=0;x<30;x++){
      if (A[i] >> x & 1) {
        bts[x].insert(i);
      }
    }
  }
  int ans = -1;
  for (int i=29;i>=0;i--){
    bool st = x >> i & 1;
    if (st && bts[i].size() % 2 == 0) {
      int cnt = (int)A.size();
      for (auto it = bts[i].begin(); it != bts[i].end();) {
        int a = *it;
        int b = *++it;
        ++it;
        for (auto jt = A.lower_bound(a); jt != A.upper_bound(b); ++jt) {
          cnt--;
        }
        cnt++;
      }
      ans = max(ans, cnt);
      dbg(ans, cnt);
    }
    if (!st && bts[i].size() % 2 == 1) {
      break;
    }
    if (!st) {
      for (auto it = bts[i].begin(); it != bts[i].end();) {
        int a = *it;
        int b = *++it;
        ++it;
        dbg(A[a], A[b]);
        int sum = 0;
        vector<int> del;
        for (auto jt = A.lower_bound(a); jt != A.upper_bound(b); ++jt) {
          sum ^= jt->second;
          dbg(sum);
          del.push_back(jt->first);
          for (int j=0;j<i;j++){
            if (jt->second >> j & 1) {
              bts[j].erase(jt->first);
            }
          }
        }
        for (int y : del) {
          A.erase(y);
        }
        A[a] = sum;
        for (int j=0;j<30;j++){
          if (sum >> j & 1) {
            bts[j].insert(a);
            dbg(j, a, sum);
          }
        }
      }
    }
    if (i == 0) {
      ans = max(ans, (int)A.size());
    }
    dbg(st, n, i, bts[i].size());
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
