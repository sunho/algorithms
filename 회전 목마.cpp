#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;

#if !defined(ONLINE_JUDGE)
#include "lib/stress.h"
void brute() {
  int n;
  cin >> n;
  vector<int> A2(n);
  for (int i=0;i<n;i++){
    cin >> A2[i];
  }
  int ans = 1e9;
  for (int msk=0;msk<1<<n;msk++) {
    int res = 0;
    int ptr = 0;
    auto A = A2;
    for (int i=0;i<n;i++){
      while (A[i] > 1) {
        int r=i;
        int rc = 0; 
        while (A[r] != 0) {
          r = (r+1) % n;
          rc++;
        }
        int l=i, lc=0;
        while (A[l] != 0) {
          l = (l-1+n) % n;
          lc++;
        }
        if (msk>>ptr&1) {
          res += rc;
          A[r]++;
        } else {
          res += lc;
          A[l]++;
        }
        ptr++;
        A[i] --;
      }
    }
    ans = min(ans, res);
  }
  cout << ans << "\n";
}

void gen_testcase(int t) {
  int n = 8;
  cout << n << '\n';
  int sum = n;
  for (int i = 0; i < n-1; i++) {
    int k = rnd(0,3);
    k = min(sum, k);
    cout << k << " ";
    sum -= k;
  }
  cout << sum << '\n';
}
#endif

/*
void solve() {
  int n;
  cin >> n;
  vector<int> A2(n);
  for (int i=0;i<n;i++){
    cin >> A2[i];
  }
  auto go = [&](bool kk){
    auto A = A2;
    int ans = 0;
    for (int i=0;i<n;i++){
      if (A[i] == 0) {
        int r=i;
        int rc = 0; 
        while (A[r] <= 1) {
          r = (r+1) % n;
          rc++;
        }
        int l=i, lc = 0;
        while (A[l] <= 1) {
          l = (l-1+n) % n;
          lc++;
        }
        if (lc > rc) {
          A[r]--;
          ans += rc;
        } else {
          // prioritize l
          A[l]--;
          ans += lc;
        }
        A[i]=1;
      }
    }
    return ans;
  };
  int ans = min(go(true),go(false));
  reverse(begin(A2),end(A2));
  ans = min(ans, min(go(true),go(false)));
  cout << ans;
}*/

void solve() {
  int n;
  cin >> n;
  vector<int> A2(n);
  for (int i=0;i<n;i++){
    cin >> A2[i];
  }
  const int inf = 1e9;

  int bias = 0;
  int ptr = 0;
  auto shift = [&]() {
    while (ptr < n) {
      if (A2[ptr] > 1) {
        int r = ptr, c = 0;
        while (A2[r] != 0) {
          r = (r-1+n) % n;
          c++;
        }
        bias += c;
        A2[r]++;
        A2[ptr]--;
        break;
      } else {
        ptr++;
      }
    }
  };

  auto go = [&](int k) {
    auto A = A2;
    int ans = bias;
    int cur = 0;
    queue<int> todo;
    for (int i=0;i<n;i++){
      ans += cur;
      if (A[i] == 0) {
        if (cur == 0) {
          todo.push(i);
        } else {
          cur--;
        }
      } else if (A[i] > 1) {
        cur += A[i]-1;
        while (cur > 0 && !todo.empty()) {
          ans += i-todo.front();
          todo.pop();
          cur--;
        }
      }
    }
    return ans;
  };
  int x = 0;
  for (int i=0;i<n;i++){
    if (A2[i] >= 1) {
      x = i;
    }
  }
  auto A3 = A2;
  int ans = inf;
  for (int i=0;i<=n;i++){
    ans = min(ans,go(i));
    shift();
  }
  A2 = A3;
  ptr = 0;
  bias = 0;
  reverse(begin(A2),end(A2));
  for (int i=0;i<n;i++){
    if (A2[i] >= 1) {
      x = i;
    }
  }
  for (int i=0;i<=n;i++){
    ans = min(ans,go(i));
    shift();
  }
  cout << ans;
}

signed main() {
#if !defined(ONLINE_JUDGE) && defined(STRESS)
  run_stress(1000, false);
#else
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#endif
}

