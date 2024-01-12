#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  cout << fixed << setprecision(10);
  int n;
  cin >> n;
  vector<pair<int,int>> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
  }
  vector<double> R(n);
  stack<pair<int,double>> stk;
  for (int i=0;i<n;i++){
    double r = A[i].second;
    int x = A[i].first;
    while (!stk.empty()) {
      ll diff = x - stk.top().first;
      double r2 = diff*diff/(4*stk.top().second);
      r = min(r, r2);
      if (r > stk.top().second) {
        stk.pop();
      } else{
        break;
      }
    }
    R[i] = r;
    stk.push({x, r});
  }
  for (int i=0;i<n;i++){
    cout << R[i] << "\n";
  }

}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
