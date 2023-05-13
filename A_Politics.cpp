#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<string> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<int> left(n);
  vector<int> cnt(n);
  for (int i=0;i<n;i++){
    for (int j=0;j<k;j++) {
      if (A[0][j] == A[i][j]) {
        cnt[i]++;
      }
    }
  }
  iota(begin(left), end(left), 0);
  for (int i=0;i<k;i++){
    int yes=0, no=0;
    for (int j : left) {
      if (A[j][i] == '+') yes++;
      else no++;
    }
    if (A[0][i] == '+') {
      if (yes <= no) {
        vector<pair<int,int>> cands;
        for (int j : left) {
          cands.push_back({cnt[j], j});
        }
        sort(rbegin(cands), rend(cands));
        for (int j=0;j<yes-no;j++){
          
        }
      }
    } else {
      swap(yes, no);
      if (yes <= no) {
        
      }
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
