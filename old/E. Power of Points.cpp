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
    vector<int> A(n);
    for (int i=0;i<n;i++)
      cin >> A[i];
    vector<int> id(n);
    iota(begin(id), end(id), 0);
    sort(begin(id), end(id), [&](int i, int j) { 
        return A[i] < A[j];
        });
    sort(begin(A), end(A));
    vector<ll> pf(n+1);
    for (int i=0;i<n;i++){
      pf[i+1]=pf[i]+A[i];
    }
    vector<ll> ans(n);
    for (int i=0;i<n;i++){
      ans[id[i]] = pf[n] - pf[i] - pf[i+1] + n + (ll)A[i]*(2*i+1-n);
    }
    for (ll a : ans)
      cout << a << " ";
    cout << "\n";
  }
}
