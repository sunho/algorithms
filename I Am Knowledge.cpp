#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<pair<int,int>> A(n);
  vector<pair<int,int>> B,C;
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
    if (A[i].second - A[i].first >= 0) {
      B.push_back({A[i].first, A[i].second});
    } else {
      C.push_back({A[i].first, A[i].second});
    }
  }
  sort(begin(B),end(B),[&](auto a, auto b){
    return pair<int,int>(a.first, -a.second) < pair<int,int>(b.first, -b.second);
  });
  ll cur = 0;
  for (int i=0;i<(int)B.size();i++){
    if (cur < B[i].first) {
      cout << 0;
      return;
    }
    cur -= B[i].first;
    cur += B[i].second;
  }
  sort(begin(C),end(C),[&](auto a, auto b){
    return pair<int,int>(-a.second, a.first) < pair<int,int>(-b.second, b.first);
  });
  for (int i=0;i<(int)C.size();i++){
    if (cur < C[i].first) {
      cout << 0;
      return;
    }
    cur -= C[i].first;
    cur += C[i].second;
  }
  cout << 1;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
