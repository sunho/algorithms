#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

struct fenwick_tree {
  // [-bias, n - bias)
  fenwick_tree(int n, int bias=0) : sums(n), bias(bias) {}
  void update(int pos, ll dif) { // a[pos] += dif
    pos += bias;
    for (; pos < sums.size(); pos |= pos + 1) sums[pos] += dif;
  }
  ll query(int pos) { // sum of values in [0, pos)
    pos += bias;
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) res += sums[pos-1];
    return res;
  }
  ll query(int l, int r) { // sum of values in [l, r)
    return query(r) - query(l);
  }
  int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
    // Returns n if no sum is >= sum, or -1 if empty sum is.
    if (sum <= 0) return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1) {
      if (pos + pw <= sums.size() && sums[pos + pw-1] < sum)
        pos += pw, sum -= sums[pos-1];
    }
    return pos-bias;
  }
private:
  vector<ll> sums;
  ll bias;
};

void solve() {
  int n;
  cin >> n;
  fenwick_tree FT(n);
  vector<int> A(n);
  for(int i=0;i<n;i++) {
    cin >> A[i];
    FT.update(A[i]-1, 1);
  }
  const int N = log2(n) + 2;
  int gans = 1e9;
  for(int a=0;a <= N;a++) {
    for(int b=0;b<=N;b++){
      for(int c=0;c<=N;c++){
        array<int,3> lens = {1 << a, 1 << b, 1 << c};
        if (lens[0] + lens[1] + lens[2] < n) continue;
        int sum = 0;
        int last = 0;
        for(int i=0;i<3;i++){
          int k = FT.lower_bound(sum + lens[i]);
          if (k == n || FT.query(last,k+1) > lens[i]) {
            k--;
          }
          ll ss = FT.query(last,k+1);
          sum += ss;
          last = k+1;
        }
        if (sum == n) {
          gans = min(gans, lens[2]+lens[1]+lens[0]-n);
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
