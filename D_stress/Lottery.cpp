#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, l;
  cin >> n >> l;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  int m = n-l+1;
  int q;
  cin >> q;
  vector<int> Q;
  for (int i=0;i<q;i++){
    int x;
    cin >> x;
    Q.push_back(l-x);
  }
  Q.push_back(0);
  vector<int> id(q+1);
  iota(begin(id),end(id),0);
  sort(rbegin(id),rend(id),[&](int i, int j) {
    return Q[i] < Q[j];
  });
  vector<int> inv(q+1);
  for (int i=0;i<=q;i++){
    inv[id[i]] = i;
  }
  sort(rbegin(Q),rend(Q));
  vector<int> mapping(l+1,-1);
  for (int i=q;i>=0;i--){
    mapping[Q[i]] = i;
  }
  for (int i=0;i<=l;i++) {
    if (mapping[i] == -1) {
      mapping[i] = mapping[i-1];
    }
  }
  vector<vector<int>> ans(q+1, vector<int>(m));
  deque<int> intervals;
  for (int i=0;i<m;i++){
    int score = 0;
    for (int j=0;j<l;j++){
      score += A[j] == A[i+j];
    }
    intervals.push_back(score);
    ans[mapping[score]][0]++;
  }
  for (int i=1;i<m;i++){
    for (int j=0;j<m-1;j++){
      intervals[j] -= A[j] == A[i-1];
      intervals[j] += A[j+l] == A[i+l-1];
    }
    int score = 0;
    for (int j=0;j<l;j++){
      score += A[i+j] == A[j];
    }
    intervals.push_front(score);
    intervals.pop_back();
    for (int x : intervals) {
      ans[mapping[x]][i]++;
    }
  }
  for (int i=1;i<=q;i++) {
    for (int j=0;j<m;j++){
      ans[i][j] += ans[i-1][j];
    }
  }
  for (int i=0;i<q;i++){
    for (int j=0;j<m;j++){
      cout << ans[inv[i]][j] - 1 << " ";
    }
    cout << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
