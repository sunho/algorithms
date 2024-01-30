#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    A[i] = s[i] - '0';
  }
  vector<int> used(n);
  vector<int> done((n+1)/2);
  vector<int> ans(n);
  for (int i=0;i<n/2;i++) {
    if (done[i]) continue;
    done[i] = true;
    int mx = max(A[i], A[n-i-1]);
    tuple<int,int> mx_dup = {0,0};
    tuple<int,int,int> mx_pair = {0,0,0};
    for (int j=0;j<n/2;j++) {
      int k = n-j-1;
      if (used[j] && used[k]) continue;
      if (A[j] == A[k]) {
        mx_dup = max(mx_dup,{A[j], j});
      } else {
        auto go = [&](int a) {
          for (int z=j+1;z<(n+1)/2;z++) {
            int z2 = n-1-z;
            if (z != z2 && A[z] == A[z2]) continue;
            if (done[z]) {
              if (!used[z] && a == A[z]) {
                mx_pair = max(mx_pair, {a, j, z});
              } 
              if (!used[z2] && a == A[z2]) {
                mx_pair = max(mx_pair, {a, j, z});
              } 
            } else {
              if ((!used[z2] || !used[z]) && a == min(A[z2],A[z])) {
                mx_pair = max(mx_pair, {a, j, z});
              } 
            }
          }
          
        };
        if (done[j]) {
          if (!used[j])
            go(A[j]);
          if (!used[k])
            go(A[k]);
        } else {
          go(min(A[j],A[k]));
        }
        int a1 = min(A[j],A[k]);
      }
    }
    if (get<0>(mx_dup) <= mx && get<0>(mx_pair) <= mx) {
      if (A[i] > A[n-i-1]) {
        used[i] = true;
      }
      if (A[i] < A[n-i-1]) {
        used[n-i-1] = true;
      }
      ans[i] = ans[n-i-1] = mx;
    } else if (get<0>(mx_dup) < get<0>(mx_pair)) {
      auto [m, x, y] = mx_pair;
      ans[i] = ans[n-i-1] = m;
      if (!done[x]) {
        ans[x] = ans[n-x-1] = max(A[x],A[n-x-1]);
        used[x] = true;
        used[n-1-x] = true;
      } else {
        if (A[x] == m && !used[x])
          used[x] = true;
        else
          used[n-1-x] = true;
      }
      if (!done[y]) {
        ans[y] = ans[n-y-1] = max(A[y],A[n-y-1]);
        used[y] = true;
        used[n-1-y] = true;
      } else {
        if (A[y] == m && !used[y])
          used[y] = true;
        else
          used[n-1-y] = true;
      }
      done[x] = true;
      done[y] = true;
    } else {
      auto [m, x] = mx_dup;
      used[x] = true;
      used[n-1-x] = true;
      ans[i] = ans[n-i-1] = m;
    }
  }
  if (n%2 == 1) {
    int mx = 0;
    for (int i=0;i<n;i++){
      if (!used[i]) {
        mx = max(mx, A[i]);
      }
    }
    ans[n/2] = max(mx, A[n/2]);
  }
  for (int x : ans) {
    cout <<x;
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
