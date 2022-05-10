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
  vector<int> A(n);
  vector<int> p(n+1);
  vector<int> aux;
  vector<int> aux_pos;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    A[i] = a;
    int pos = lb(aux, a);
    if (pos == (int)aux.size()) {
      if (aux.empty()) {
        p[i] = -1;
      } else {
        p[i] = aux_pos.back();
      }
      aux.push_back(a);
      aux_pos.push_back(i);
    } else {
      if (pos > 0) {
        p[i] = aux_pos[pos-1];
      } else {
        p[i] = -1;
      }
      aux_pos[pos] = i;
      aux[pos] = a;
    }
  }
  deque<int> ans;
  int v = aux_pos.back();
  while (v != -1) {
    ans.push_front(A[v]);
    v = p[v];
  }
  cout << ans.size() << "\n";
  for(int x : ans) cout << x << " ";
  cout << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
