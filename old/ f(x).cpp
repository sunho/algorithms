#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 1e9;

__int128_t ipow(__int128_t x, int k) {
  __int128_t res = 1;
  while (k) {
    if (k&1) res = res*x;
    x = x*x;
    k/=2;
  }
  return res;
}

vector<ll> poly_mult(vector<ll> A, vector<ll> B) {
  vector<ll> res(A.size()+B.size()-1);
  for (int i=0;i<A.size();i++){
    for (int j=0;j<B.size();j++){
      res[i+j] += A[i]*B[j];
    }
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  vector<ll> A(n+1);
  for (int i=0;i<n+1;i++){
    cin >> A[i];
  }
  if (n != (int)sqrt(n)*(int)sqrt(n)) {
    cout << "-1";
    return;
  }
  int m = (int)sqrt(n);
  vector<ll> B(m+1);
  bool yes = false;
  vector<ll> ans;
  auto work = [&]() {
    int last = m;
    if (m >= 3) {
      for (int k=-100;k<=100;k++){
        if (m*ipow(B[0],m)*k== A[1]) {
          B[1] = k;
        }
      }
      for (int k=-100;k<=100;k++){
        __int128_t coeff = m*(m-1)/2*ipow(B[0],m-1)*B[1]*B[1] + m*ipow(B[0],m)*k;
        if (coeff == A[2]) {
          B[2] = k;
        }
      }
      for (int k=-100;k<=100;k++){
        __int128_t coeff = m*(m-1)*ipow(B[0],m-1)*B[1]*B[2] + m*(m-1)*(m-2)/6*ipow(B[0],m-2)*B[1]*B[1]*B[1] + m*ipow(B[0],m)*k;
        if (m == 3) {
          coeff += B[0]*B[1];
        }
        if (coeff == A[3]) {
          B[3] = k;
        }
      }
      last = m-3;
      if (m == 5) {
        for (int k=-100;k<=100;k++){
          __int128_t coeff = m*(m-1)*(m-2)/2*ipow(B[0],m-2)*B[1]*B[1]*B[2] + m*(m-1)*ipow(B[0],m-1)*(B[1]*B[3]) + m*(m-1)/2*ipow(B[0],m-1)*(B[2]*B[2]) + m*(m-1)*(m-2)*(m-3)/(4*3*2*1)*ipow(B[0],m-3)*B[1]*B[1]*B[1]*B[1] + m*ipow(B[0],m)*k;
          if (coeff == A[4]) {
            B[4] = k;
          }
        }
        last = m-4;
      }
    }
    reverse(begin(A),end(A));
    reverse(begin(B),end(B));
    auto dfs = [&](auto&& self, int i) -> void {
      if (i == last) {
        vector<ll> C(n+1);
        for (int i=m;i>=0;i--){
          vector<ll> BB = {1};
          for (int j=0;j<i;j++){
            BB = poly_mult(BB, B);
          }
          for (int j=0;j<BB.size();j++){
            C[j] += B[i]*BB[j];
          }
        }
        if (A == C) {
          ans = B;
          yes = true;
        }
        return;
      }
      for (int x=-100;x<=100;x++){
        B[i] = x;
        self(self, i+1);
      }
    };
    dfs(dfs, 0);
    reverse(begin(A),end(A));
    reverse(begin(B),end(B));
  };
  for (int k=0;k<=100;k++){
    if (ipow(k,m+1) == A[0]) {
      B[0] = k;
    }
  }
  work();
  for (int k=-100;k<=0;k++){
    if (ipow(k,m+1) == A[0]) {
      B[0] = k;
    }
  }
  work();
  if (yes) {
    reverse(begin(ans),end(ans));
    cout << m << "\n";
    for (int a : ans) {
      cout << a << " ";
    }
    cout << "\n";
  } else {
    cout << -1 << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
