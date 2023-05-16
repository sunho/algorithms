#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m, k;
  cin >> n >> m >> k;
  using bytes = bitset<160>;
  vector<bytes> A(n), B(m);
  string conv = "0123456789abcdef";
  auto to_bytes = [&](string s) {
    bytes res;
    for (int z=0;z<k;z++) {
      int b = conv.find(s[k-z-1]);
      res |= bytes(b) << (z << 2);
    }
    return res;
  };
  for (int i=0;i<n;i++){
    string s;
    cin >> s;
    A[i] = to_bytes(s);
  }
  for (int i=0;i<m;i++){
    string s;
    cin >> s;
    B[i] = to_bytes(s);
  }
  
  vector<int> ans(m, -1);
  array<bytes, 160> basis{};
  bool zero = false;
  for (int i=0;i<n;i++) {
    bytes mask = A[i];
    for (int d=0;d<160;d++){
      if (!mask[d]) continue;
      if (basis[d] == 0) {
        basis[d] = mask;
        break;
      }
      mask ^= basis[d];
    }
    if (mask == 0) {
      zero = true;
    }
    for (int j=0;j<m;j++){
      if (ans[j] != -1) continue;
      bytes mask = B[j];
      if (mask == 0) {
        if (zero)
          ans[j] = i+1;
        continue;
      }
      bool ok = true;
      for (int d=0;d<160;d++){
        if (!mask[d]) continue;
        if (basis[d] == 0) {
          ok = false;
          break;
        }
        mask ^= basis[d];
      }
      if (ok) {
        ans[j] = i + 1;
      }
    }
  }

  for (int i=0;i<m;i++){
    cout << ans[i] << "\n";
  }
}
