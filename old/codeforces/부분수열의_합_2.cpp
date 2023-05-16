#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, s;
  cin >> n >> s;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  map<int,int> left, right;
  int m = n/2;
  int m2 = n-m;
  for (int mask=1;mask<(1<<m);mask++){
    int sum = 0;
    for (int i=0;i<m;i++){
      if (mask & (1 << i)) {
        sum += A[i];
      }
    }
    left[sum]++;
  }
  for (int mask=1;mask<(1<<m2);mask++){
    int sum = 0;
    for (int i=0;i<m2;i++){
      if (mask & (1 << i)) {
        sum += A[i+m];
      }
    }
    right[sum]++;
  }
  ll ans = left[s] + right[s];
  for (auto [a,c] : left) {
    if (right.count(s-a)) {
      ans += (ll)left[a] * right[s-a];
    }
  }
  cout << ans;
}
