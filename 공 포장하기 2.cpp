#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  int cand = 0;
  int mx = 0;
  for (int i=0;i<n;i++){
    cin >> A[i];
    int r = (A[i]+n-1)/n-1;
    cand += r;
    A[i] -= r*n;
  }
  map<int,int> cnt;
  int rem = 0;
  for (int i=0;i<n;i++){
    if (A[i] != 0) {
      cnt[A[i]]++;
      rem++;
    }
  }
  int ans = cand+rem;
  for (auto [x,c] : cnt) {
    int cand2 = cand;
    cand2 += x;
    rem-=c;
    cand2 += rem;
    ans = min(ans, cand2);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
