#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "lib/debug.h"
#define dbg(...) std::cerr << __DEBUG_UTIL__::outer << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &x : v)
      cin >> x;

  vector<pair<int,int>> d(n);
  vector<vector<int>>A(n, vector<int>(3, 53));
  for (int i=0;i<n;i++){
    A[i][1] = i+5;
  }
  dbg(A);


  sort(v.begin(), v.end());

  cout << v[n - 2] * v[n - 1] << endl;
}

#if !defined(ONLINE_JUDGE)
#include "lib/stress.h"
void brute() {
  int n;
    cin >> n;
    vector<int> v(n);
    for (int &x : v)
        cin >> x;

    int ans = v[0] * v[1];

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans = max(ans, v[i] * v[j]);

    cout << ans << endl;
}

void gen_testcase(int t) {
  int n = 10;
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    cout << rnd(-1000, 1000) << ' ';
  }
  cout << '\n';
}
#endif

signed main() {
#if !defined(ONLINE_JUDGE) && defined(STRESS)
  run_stress(100, true);
#else
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
#endif
}
