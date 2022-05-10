#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  const int N = 10000;
  vector<vector<int>> idx(N+1);
  int n;
  int s;
  cin >> n;
  cin >> s;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    idx[a].push_back(i);
  }
  int p=N;
  while (p > 0) {
    if (idx[p].empty()) {
      p--;
      continue;
    }
    ll sum = 0;
    int last;
    int li=0;
    for(int i=p;i>0;i--) {
      if (i==p) {
        last = idx[i].back();
        sum += i;
      } else {
        int j = lb(idx[i], last);
        if (j == 0) {
          break;
        }
        --j;
        last = idx[i][j];
        sum += i;
      }
      li++;
      if (sum >= s) {
        break;
      }
    }
    if (sum >= s) {
      cout << li << "\n";
      return;
    }
    p -= li;
  }
  cout << 0 << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
