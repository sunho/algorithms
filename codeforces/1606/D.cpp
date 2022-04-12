#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> M(n, vector<int>(m));
  vector<int> rev(n);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> M[i][j];
    }
  }
  iota(all(rev), 0);
  sort(all(rev), [&](int a, int b) {
    return M[a] < M[b];
  });
  auto M2 = M;
  for(int i=0;i<n;i++) {
    M2[i] = M[rev[i]];
  }
  M = M2;
  vector<multiset<int>> A(n);
  vector<multiset<int>> B(n);
  for(int i=0;i<n;i++) {
    A[i].insert(M[i][0]);
    for(int j=1;j<m;j++) {
      B[i].insert(M[i][j]);
    }
  }
  for(int k=0;k<m-1;k++) {
    vector<multiset<int>> L(2), R(2);
    L[0].insert(*A[0].rbegin());
    R[0].insert(*B[0].begin());
    for(int i=1;i<n;i++) {
      L[1].insert(*A[i].begin());
      R[1].insert(*B[i].rbegin());
    }
    bool ok = false;
    int idx = 0;
    while (idx < n-1){
      int maxA_b = *L[0].rbegin();
      int minA_r = *L[1].begin();
      int minB_b = *R[0].begin();
      int maxB_r = *R[1].rbegin();
      if (minA_r > maxA_b && minB_b > maxB_r) {
        ok = true;
        break;
      }
      idx++;
      L[0].insert(*A[idx].rbegin());
      R[0].insert(*B[idx].begin());
      L[1].erase(L[1].find(*A[idx].begin()));
      R[1].erase(R[1].find(*B[idx].rbegin()));
    }
    if (ok) {
      cout << "YES" << "\n";
      idx++;
      string ans;
      for(int i=0;i<idx;i++){
        ans.push_back('B');
      }
      for(int i=idx;i<n;i++){
        ans.push_back('R');
      }
      string ans2 = ans;
      for(int i=0;i<n;i++){
        ans2[rev[i]] = ans[i];
      }
      cout << ans2 << " " << k+1 << "\n";
      return;
    }
    for(int i=0;i<n;i++){
      B[i].erase(B[i].find(M[i][k+1]));
      A[i].insert(M[i][k+1]);
    }
  }
  cout << "NO" << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
