#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,a,b;
  cin >> n >> a >> b;
  vector<int> slots(b+1);
  for(int i=0;i<a;i++) {
    slots[i%(b+1)]++;
  }
  for(int i=0;i<b;i++) {
    for(int j=0;j<slots[i];j++){
      cout << "R";
    }
    cout << "B";
  }
  for(int i=0;i<slots[b];i++){
    cout << "R";
  }
  cout << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
