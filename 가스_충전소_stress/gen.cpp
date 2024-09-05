#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll mn, ll mx) {
  uniform_int_distribution<ll> gen(mn, mx);
  return gen(rng);
}

vector<int> rnd_array(int n, int mn, int mx) {
  int in = 0;
  vector<int> A(n);
  int m = mx - mn + 1;
  for (int i = 0; i < m && in < n; ++i) {
    int rm = m - i;
    int rn = n - in;
    if (rnd(0, rm - 1) < rn)
      A[in++] = i;
  }
  assert(in == n);
  return A;
}

vector<pair<int, int>> rnd_tree(int n) {
  vector<pair<int, int>> res;
  for (int i = 2; i <= n; i++) {
    res.push_back({i, rnd(1, i - 1)});
  }
  return res;
}

int main() {
  int n = 5;
  int X = 100, F = 100;
  cout << n << " " << X << " " << F << "\n";
  vector<int> A(99);
  iota(begin(A),end(A),1);
  int ptr = 0;
  shuffle(begin(A),end(A), rng);
  vector<tuple<int,int,int>> B;
  for (int i=0;i<n;i++){
    B.push_back({A[ptr],A[ptr+1],A[ptr+2]});
    ptr+=3;
  }
  sort(begin(B),end(B));
  for (auto [x,y,z] : B) {
    cout << x << " " << y << " " << z << "\n";
  }
}
