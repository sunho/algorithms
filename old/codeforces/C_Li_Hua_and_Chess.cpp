#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<int,int> solve() {
  int n,m;
  cin >> n >> m;

  pair<int,int> ans;
  auto query = [&](int x, int y) {
    cout << "? " << x << " " << y << endl;
    int q;
    cin >> q;
    return q;
  };
  int q = query(1,1);
  if (q == 0) {
    return {1,1};
  }
  if (1+q <= n && 1+q <=m) {
    int q1 = query(q+1,1);
    int q2 = query(1,q+1);
    if (q1 == 0) {
      return {q+1,1};
    }
    if (q2 == 0) {
      return {1,q+1};
    }
    if (q1 == q2) {
      return {q+1,q+1};
    } else if (q1 < q2) {
      return {1+q, 1+q1};
    } else {
      return {1+q2, 1+q};
    }
  }
  if (1 + q <= n) {
    int q1 = query(q+1,1);
    if (q1 == 0) {
      return {q+1,1};
    }
    return {q+1, 1+q1};
  }
  int q1 = query(1,1+q);
  if (q1 == 0) {
    return {1,1+q};
  }
  return {1+q1, 1+q};
  
}

int main() {
  int t;
  cin >> t;

  while (t--){
    auto [x,y] = solve();
    cout << "! " << x << " " << y << endl;
  }
}
