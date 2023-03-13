#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n;
  cin >> n;
  vector<vector<string>> A(3, vector<string>(n));
  map<string, int> O;
  for(int i=0;i<3;i++)
    for (int j=0;j<n;j++) {
      cin >> A[i][j];
      O[A[i][j]]++;
    }
  for (int i=0;i<3;i++){
    int score = 0;
    for (int j=0;j<n;j++) {
      switch (O[A[i][j]]) {
        case 1: {
          score += 3;
          break;
        }
        case 2: {
          score += 1;
          break;
        }
      }
    }
    cout << score << " ";
  }
  cout << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
