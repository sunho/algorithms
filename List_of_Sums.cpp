#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve(const vector<int>& A, int n, int k, int a0, vector<ll>& res) {
  if (a0 <= 0 || a0 > k) return false;
  res[0] = a0;
  multiset<int> B(begin(A),end(A));
  for (int i=1;i<n;i++){
    res[i] = *B.begin() - res[0];
    for (int j=0;j<i;j++){
      if (B.find(res[i]+res[j]) == B.end()) {
        return false;
      }
      B.erase(B.find(res[i]+res[j]));
    }
  }
  vector<int> sums;
  for (int i=0;i<n;i++){
    if (res[i] <= 0 || res[i] > k) { 
      return false;
    }
    for (int j=i+1;j<n;j++){
      sums.push_back(res[i]+res[j]);
    }
  }
  sort(begin(sums), end(sums));
  return sums == A;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  const int k = 1e9;
  const int N = n*(n-1)/2;
  vector<int> A(N);
  for (int i=0;i<N;i++) cin >> A[i];
  sort(begin(A),end(A));
  vector<ll> ans(n);
  for (int z=2;z<N;z++){
    if (solve(A, n, k, ((ll)A[0]+A[1]-A[z])/2, ans)) {
      for (int i=0;i<n;i++){
        cout << ans[i] << " ";
      }
      return 0;
    }
  }
  cout << -1 << "\n";
}
