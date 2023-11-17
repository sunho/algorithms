#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    int tot = 0;
    vector<vector<int>> A(n);
    vector<int> B;
    int mn = 1e9;
    for (int i=0;i<n;i++){
      int m; 
      cin >> m;
      for (int j=0;j<m;j++){
        int a;
        cin >> a;
        A[i].push_back(a);
        mn = min(mn, a);
      }
      sort(begin(A[i]),end(A[i]));
      B.push_back(A[i][1]);
    }
    sort(begin(B), end(B));
    ll ans = mn;
    for (int i=B.size()-n+1;i<B.size();i++) ans += B[i];
    cout << ans << "\n";
  }
}
