#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<tuple<int,int,int>> A(n);
  set<tuple<int,int,int>> S;
  for (int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    A[i] = {a,-b,i};
  }
  sort(begin(A), end(A));
  for (int i=0;i<n;i++){
    auto [l,r,id] = A[i];
    r*=-1;
    S.insert({r,l,id});
  }
  vector<bool> contains(n);
  for (int i=0;i<n;i++){
    auto [l,r,id] = A[i];
    r*=-1;
    S.erase({r,l,id});
    auto jt = S.upper_bound({r,1e9+5,n});
    if (jt != S.begin()) {
      contains[id] = true;
    }
  }
  for (int i=0;i<n;i++){
    auto [l,r,id] = A[i];
    r*=-1;
    S.insert({r,l,id});
  }
  vector<bool> contained(n);
  for (int i=n-1;i>=0;i--){
    auto [l,r,id] = A[i];
    r*=-1;
    S.erase({r,l,id});
    auto jt = S.lower_bound({r,0,0});
    if (jt != S.end()) {
      contained[id] = true;
    }
  }
  for (int i=0;i<n;i++){
    cout << contains[i] << " ";
  }
  cout << "\n";
  for (int i=0;i<n;i++){
    cout << contained[i] << " ";
  }
  cout << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
