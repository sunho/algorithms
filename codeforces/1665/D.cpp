#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int r = 0;
  for(int i=0;i<30;i++) {
    int k = 1 << i;
    int k2 = (1<<(i+1));
    int a = k - r, b = k - r + (1<<(i+1));
    cout << "? " << a << " " << b << endl;
    int q;
    cin >> q;
    if (q == k2) {
      r += k;
    }
  }
  cout << "! " << r << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--){
    solve();
  }

  return 0;
}
