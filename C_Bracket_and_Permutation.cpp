#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> P(2*n), Q(2*n);
  for (int i=0;i<2*n;i++) cin >> P[i], --P[i];
  for (int i=0;i<2*n;i++) cin >> Q[i], --Q[i];
  vector<char> ans(2*n, 0);
  for (int i=0;i<n;i++){
    if (P[i*2] > P[i*2+1]) {
      ans[P[i*2]] = '(';
      ans[P[i*2+1]] = ')';
    }
  }
  bool ok = true;
  for (int i=0;i<n;i++){
    if (Q[i*2] < Q[i*2+1]) {
      if (ans[Q[i*2]] == ')') ok = false;
      ans[Q[i*2]] = '(';
      if (ans[Q[i*2+1]] == '(') ok = false;
      ans[Q[i*2+1]] = ')';
    }
  }
  for (int i=0;i<2*n;i++){
    if (!ans[i]) ok = false;
  }
  int cur = 0;
  for (int i=0;i<2*n;i++){
    if (ans[P[i]] == '(') 
      cur ++;
    else if (ans[P[i]] == ')') {
      cur --;
      if (cur < 0) {
        ok = false;
      }
    }
  }
  if (cur != 0) ok = false;
  for (int i=0;i<2*n;i++){
    if (ans[Q[i]] == '(') 
      cur ++;
    else if (ans[Q[i]] == ')') {
      cur --;
      if (cur < 0) {
        ok = false;
      }
    }
  }
  if (cur != 0) ok = false;
  if (ok) {
    auto calc = [&](auto& open, auto& close, bool greator) {
      vector<int> Q2;
      for (int i=0;i<2*n;i++){
        if (ans[i] == '(') open.insert(i);
        else close.insert(i);
      }
      int cur = 0;
      for (int i=0;i<2*n;i++){
        if (cur == 0) {
          cur++;
          Q2.push_back(*open.begin());
          open.erase(open.begin());
        } else if (open.empty()) {
          cur--;
          Q2.push_back(*close.begin());
          close.erase(close.begin());
        } else if (close.empty()) {
          cur++;
          Q2.push_back(*open.begin());
          open.erase(open.begin());
        } else {
          bool cond = *open.begin() < *close.begin();
          if (cond ^ greator) {
            cur++;
            Q2.push_back(*open.begin());
            open.erase(open.begin());
          } else {
            cur--;
            Q2.push_back(*close.begin());
            close.erase(close.begin());
          }
        }
      }
      return Q2;
    };
    set<int> open, close;
    auto P2 = calc(open, close, false);
    if (P != P2) {
      ok = false;
    }
    set<int, greater<>> open2, close2;
    auto Q2 = calc(open2, close2, true);
    if (Q != Q2) {
      ok = false;
    }
  }
  if (ok) {
    for (char c : ans) {
      cout << c;
    }
  } else {
    cout << -1 << "\n";
  }
}
