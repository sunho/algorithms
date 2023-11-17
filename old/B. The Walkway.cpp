#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--){
    int n,m,d;
    cin >> n >> m >> d;
    vector<int> A(m);
    map<int,int> S;
    for (int i=0;i<m;i++){
      cin >> A[i];
      S[A[i]] = i;
    }
    sort(begin(A),end(A));
    if (A[0] != 1) {
      A.push_back(1);
    }
    A.push_back(n+1);
    sort(begin(A),end(A));
    ll ans = A.size()-1;
    for (int i=0;i<A.size()-1;i++){
      ans += (A[i+1]-A[i] - 1)/d;
    }
    int mn_i = -1;
    for (int i=1;i<A.size()-1;i++){
      if ((A[i+1]-A[i]-1)/d + (A[i]-A[i-1]-1)/d >= (A[i+1]-A[i-1]-1)/d) {
        mn_i = S[A[i]];
      }
    }
    if (mn_i == -1) {
      cout << ans << " " << 1 << "\n";
    } else {
      cout << ans - 1 << " " << mn_i+1 << "\n";
    }
  }
}
