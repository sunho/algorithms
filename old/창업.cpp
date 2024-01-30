#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  string s,t;
  cin >> s >> t;
  const int n = s.size();
  deque<char> A,B;
  for (char c : s) {
    A.push_back(c);
  }
  for (char c : t) {
    B.push_back(c);
  }
  sort(begin(A),end(A));
  sort(rbegin(B),rend(B));
  while (A.size() > (n+1)/2) {
    A.pop_back();
  }
  while (B.size() > (n)/2) {
    B.pop_back();
  }
  vector<char> ans(n);
  int fr = 0, bk = n-1;
  for (int i=0;i<n;i++){
    if (i&1) {
      if (A.empty() || B.front() > A.front()) {
        ans[fr++] = B.front();
        B.pop_front();
      } else {
        ans[bk--] = B.back();
        B.pop_back();
      }
    } else {
      if (B.empty() || B.front() > A.front()) {
        ans[fr++] = A.front();
        A.pop_front();
      } else {
        ans[bk--] = A.back();
        A.pop_back();
      }
    }
  }
  for (char c : ans) {
    cout << c;
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
