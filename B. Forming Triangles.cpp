#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti += 1) {
    int n;
    cin >> n;
    vector<int> c(n + 1);
    for (int i = 0, a; i < n; i += 1) {
      cin >> a;
      c[a] += 1;
    }
    i64 ans = 0, sum = 0;
    for (i64 ci : c) {
      ans += ci * (ci - 1) * (ci - 2) / 6;
      ans += ci * (ci - 1) / 2 * sum;
      sum += ci;
    }
    cout << ans << "\n";
  }
}
/* #include <bits/stdc++.h> */
/**/
/* using namespace std; */
/* using ll = long long; */
/**/
/* void solve() { */
/*   int n; */
/*   cin >> n; */
/*   vector<int> A(n); */
/*   for (int i=0;i<n;i++){ */
/*     cin >> A[i]; */
/*   } */
/*   sort(begin(A),end(A)); */
/*   map<int,int> cnt; */
/*   ll ans = 0; */
/*   for (int i=0;i<n;i++){ */
/*     ans += (ll)cnt[A[i]] * (i-cnt[A[i]]); */
/*     cnt[A[i]] ++; */
/*   } */
/*   for (auto [a,c] : cnt) { */
/*     ans += (ll)c*(c-1)*(c-2)/6; */
/*   } */
/*   cout << ans << "\n"; */
/* } */
/**/
/* int main() { */
/*   cin.tie(nullptr)->sync_with_stdio(false); */
/*   int t; */
/*   cin >> t; */
/*   while (t--) */
/*     solve(); */
/* } */
