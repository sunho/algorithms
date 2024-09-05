#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  int cur = 0;
  array<int,4> cnt{};
  for (int i=0;i<n/2;i++){
    char a = s[i], b = s[n-i-1];
    if (a > b) swap(a,b);
    if (a == '3' && b == 'E') {
      cur++;
    }
    if (a == '2' && b == '2') {
      cur++;
    }
    if (a == 'E' && b == 'E') {
      cnt[0] ++;
    }
    if (a == '3' && b == '3') {
      cnt[1] ++;
    }
    if (a == '2' && b == 'E') {
      cnt[2] ++;
    }
    if (a == '2' && b == '3') {
      cnt[3]++;
    }
  }
  cout << 2*cur << "\n";
  for (int i=0;i<k;i++){
    if (cnt[0] > 0 && cnt[1] > 0) {
      cnt[0]--,cnt[1]--;
      cur += 2;
    } else if (cnt[2] > 0 && cnt[3] > 0) {
      cnt[2]--, cnt[3]--;
      cur += 2;
    } else if (cnt[2] >= 2) {
      cur++;
      cnt[2] -= 2;
      cnt[0] ++;
    } else if (cnt[2] > 0 && cnt[1] > 0)  {
      cur++;
      cnt[2]--, cnt[1]--;
      cnt[3]++;
    } else if (cnt[3] >= 2) {
      cur++;
      cnt[3] -= 2;
      cnt[1]++;
    } else if (cnt[3] > 0 && cnt[0] > 0) {
      cur++;
      cnt[3]--, cnt[0]--;
      cnt[2]++;
    }
    cout << 2*cur << "\n";
  }
}
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
