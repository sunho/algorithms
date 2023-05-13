#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<int> A(n), B(n);
  for (int i=0;i<n;i++){
    cin >> A[i] >> B[i];
    --A[i],--B[i];
  }

  vector<vector<int>> M(m);
  for (int i=0;i<n;i++){
    M[A[i]].push_back(i);
    M[B[i]].push_back(i);
  }

  map<int,int> cnt;
  vector<int> imos(m+1);
  int r = 0;
  for (int l=0;l<m;l++){
    while (r < m && cnt.size() != n) {
      for (int v : M[r]) {
        cnt[v]++;
      }
      r++;
    }
    if (cnt.size() == n) {
      imos[r-l-1]++;
      imos[m-l-1+1]--;
    }
    for (int v : M[l]) {
      cnt[v]--;
      if (cnt[v] == 0)
        cnt.erase(v);
    }
  }
  for (int i=1;i<=m;i++){
    imos[i] += imos[i-1];
  }
  for (int i=0;i<m;i++){
    cout << imos[i] << " ";
  }
}
