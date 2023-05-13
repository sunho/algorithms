#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  map<int,int> cnt;
  while (n--) {
    int k;
    cin >> k;
    cnt[k]++;
  }
  int ans = 0;
  for (auto [_, c] : cnt) {
    ans += c/2;
  }
  cout << ans << "\n";
}
