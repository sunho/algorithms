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
  int n;
  cin >> n;
  vector<vector<int>> A(n, vector<int>(5));
  for(int i=0;i<n;i++){
    for(int j=0;j<5;j++){
      cin >> A[i][j];
    }
  }
  bool ans = false;
  for(int a=0;a<5;a++){
    for(int b=a+1;b<5;b++){
      array<int,3> rem = {0,0,0};
      for(int i=0;i<n;i++){
        if (A[i][a] == 1 && A[i][b] == 1) {
          rem[2]++;
        } else if (A[i][a] == 1) {
          rem[0]++;
        } else if (A[i][b] == 1) {
          rem[1]++;
        }
      }
      if (rem[0] + rem[1] + rem[2] != n) {
        continue;
      }
      if (abs(rem[1] - rem[0]) <= rem[2]) {
        ans = true;
      }
    }
  }
  if(ans) {
    cout << "YES" << "\n";
  } else{
    cout << "NO" << "\n";
  }
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
