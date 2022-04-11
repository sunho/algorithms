#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int ilog2(ll x) { return 63 - __builtin_clzll(x); }
int ilog2(int x) { return 31 - __builtin_clz(x); }

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i=0;i<n;i++) {
    cin >> A[i];
  }
  sort(all(A));
  const int N = ilog2(n) + 1;
  int gans = 1e9;
  for(int a=0;a<=N;a++) {
    for(int b=0;b<=N;b++){
      for(int c=0;c<=N;c++){
        array<int,3> lens = {1 << a, 1 << b, 1 << c};
        int len_sum = lens[0] + lens[1] + lens[2];
        if (len_sum < n) continue;
        int sum = 0;
        int last = 0;
        for(auto len : lens){
          int c = A[min(sum + len - 1, n-1)];
          int k = upper_bound(all(A), c) - A.begin() - 1;
          if (k-last+1 > len) {
            k = lower_bound(all(A), c) - A.begin() - 1;
          }
          sum += k-last+1;
          last = k+1;
        }
        if (sum == n) {
          gans = min(gans, len_sum-n);
        }
      }
    }
  }
  cout << gans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
