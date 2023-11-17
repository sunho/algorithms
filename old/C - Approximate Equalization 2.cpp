#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> A(n);
  ll sum = 0;
  for (int i=0;i<n;i++){
    cin >> A[i];
    sum += A[i];
  }
  ll target = sum / n;
  ll neg=0,pos=0;
  for (int i=0;i<n;i++){
    if (A[i] < target) {
      pos += target-A[i];
    }
    if (A[i] > target + 1) {
      neg += A[i]-(target+1);
    }
  }
  cout << max(neg, pos) << "\n";
}
