#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int _;
  cout << "+ " << n << endl;
  cin >> _;
  assert(_==1);
  cout << "+ " << n+1 << endl;
  cin >> _;
  assert(_==1);
  auto query = [&](int i, int j) {
    cout << "? " << i + 1 << " " << j + 1 << endl;
    int d;
    cin >> d;
    assert(d>=0);
    return d;
  };
  vector<int> dist1(n);
  for (int i=1;i<n;i++){
    dist1[i] = query(0,i);
  }
  int mx = max_element(begin(dist1),end(dist1))-begin(dist1);
  vector<int> dist2(n);
  for (int i=0;i<n;i++){
    if (i != mx) {
      dist2[i] = query(mx, i);
    }
  }
  cout << "! ";
  for (int i=0;i<n;i++) {
    if (dist2[i] % 2 == 0) 
      cout << n-dist2[i]/2 << " ";
    else
      cout << (dist2[i]+1)/2 << " ";
  }
  for (int i=0;i<n;i++){
    dist2[i] = n-dist2[i]-1;
  }
  for (int i=0;i<n;i++) {
    if (dist2[i] % 2 == 0) 
      cout << n-dist2[i]/2 << " ";
    else
      cout << (dist2[i]+1)/2 << " ";
  }
  cout << endl;
  cin >> _;
  assert(_==1);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
