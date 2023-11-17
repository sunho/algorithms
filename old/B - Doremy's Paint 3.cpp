#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  map<int,int> cnt;
  for (int i=0;i<n;i++){
    int a;
    cin >> a; 
    cnt[a]++;
  }
  if (cnt.size() == 1) {
    cout << "Yes" << "\n";
    return; 
  } else if (cnt.size() == 2) {
    int x = cnt.begin()->second;
    int y = (++cnt.begin())->second;
    if (x > y) {
      swap(x,y);
    }
    if (x == n/2) {
      cout << "Yes" << "\n";
      return;
    }
  }
  cout << "No" << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
