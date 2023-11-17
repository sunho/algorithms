#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i=0;i<n;i++) {
      cin >> A[i];
    }
    map<int,int> cnt;
    long long ans = 0;
    for (int i=0;i<n;i++){
      A[i] -= i;
      ans += cnt[A[i]];
      cnt[A[i]] ++;
    }
    cout << ans << "\n";
  }

}
