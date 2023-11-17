#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> B(n-1);
  for (int i=0;i<n-1;i++){
    cin >> B[i];
  }
  vector<int> pf(n);
  for (int i=0;i<n-1;i++){
    pf[i+1] = pf[i] ^ B[i];
  }
  if (n%2 == 1) {
    int sum = 0;
    for (int i=1;i<n;i++) {
      sum ^= pf[i];
    }
    for (int i=0;i<n;i++){
      sum ^= i;
    }
    cout << sum << " ";
    for (int i=1;i<n;i++){
      cout << (sum ^ pf[i]) << " ";
    }
  } else {
    vector<int> tgt(30);
    for (int i=0;i<30;i++) {
      for (int j=0;j<n;j++) {
        if ((j >> i)&1) {
          tgt[i]++;
        }
      }
    }
    vector<int> src(30);
    for (int i=0;i<30;i++) {
      for (int j=1;j<n;j++) {
        if ((pf[j] >> i)&1) {
          src[i]++;
        }
      }
    }
    int b = 0;
    for (int i=0;i<30;i++){
      if (tgt[i] != src[i]) {
        b ^= (1<<i);
      }
    }
    cout << b << " ";
    for (int i=1;i<n;i++){
      cout << (b ^ pf[i]) << " ";
    }
  }
}
