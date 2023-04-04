#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  const int N = 1e6;
  vector nums(N+1, 0);
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    nums[a]++;
  }
  int ans = 1;
  for (int g=1;g<=N;g++){
    int cnt = 0;
    for (int i=g;i<=N;i+=g){
      cnt += nums[i];
    }
    if (cnt >= 2) {
      ans = g;
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
