#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  set<int> s;
  int n;
  cin >> n;
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    s.insert(a);
  }
  cout << s.size() << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
