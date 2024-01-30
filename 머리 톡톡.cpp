#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  const int N = 1e6;
  vector<int> cnt(N+1);
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
    cnt[A[i]] ++;
  }
  vector<int> ans(N+1);
  for (int i=1;i<=N;i++){
    for (int j=i;j<=N;j+=i){
      ans[j] += cnt[i];
    }
  }
  for (int i=0;i<n;i++){
    cout << ans[A[i]] - 1 << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
