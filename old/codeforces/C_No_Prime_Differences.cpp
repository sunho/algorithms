#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> lp, pr;

void sieves(int PN, vector<ll>& lp, vector<ll>& pr) {
  lp.assign(PN+1,0);
  for (int i=2;i<=PN;i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j=0;j<pr.size()&&pr[j]<=lp[i]&&i*pr[j]<=PN;j++) {
      lp[i * pr[j]] = pr[j];
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> A(n, vector<int>(m));
  if (lp[n] != n) {
    int cnt = 0;
    for (int j=0;j<m;j++){
      for (int i=0;i<n;i++){
        A[i][j] = cnt++;
      }
    }
  } else if (lp[m] != m) {
    int cnt = 0;
    for (int i=0;i<n;i++){
      for (int j=0;j<m;j++){
        A[i][j] = cnt++;
      }
    }
  } else {
    int cnt = 0;
    for (int i=0;i<n;i++){
      for (int j=0;j<m;j++){
        A[2*i%n][j] = i*m+j*(m-1)%m;
      }
    }
    // for (int i=0;i<n;i++){
    //   if (i%2 == 0) {
    //     A[n-1][i] = n*m-cnt;
    //   }
    // }
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cout << A[i][j] + 1 << " ";
    }
    cout << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  const int N = 1000;
  sieves(N, lp, pr);
  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
