#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
  int n,m;
  cin >> n >> m;
  string s;
  cin >> s;
  auto calc = [&](int a, vector<int>& B) -> bool {
    int cur = 0;
    B.assign(m, 0);
    for (int i=0;i<m;i++){
      if (cur >= s.size()) {
        return false;
      }
      if ((s[cur] - '0') % a != 0) {
        if (cur+1 >= s.size()) {
          return false;
        }
        int d = (s[cur] - '0') * 10 + (s[cur+1]-'0');
        if (d % a != 0) {
          return false;
        }
        int nn = d/a;
        if (nn > 9)
          return false;
        B[i] = nn;
        cur+=2;
      } else {
        int d = s[cur] - '0';
        if (d % a != 0) {
          return false;
        }
        int nn = d/a;
        if (nn > 9)
          return false;
        B[i] = nn;
        cur++;
      }
    }
    return true;
  };
  auto check = [&](int a, vector<int>& B, vector<int>& A) -> bool {
    A.assign(n, 0);
    A[0] = a;
    int cur = 0;
    for (int i=0;i<n;i++){
      for (int j=0;j<m;j++){
        if (cur >= s.size()) {
          return false;
        }
        if (B[j] == 0) {
          if (s[cur] != '0')
            return false;
          cur++;
          continue;
        }
        if ((s[cur] - '0') % B[j] != 0) {
          if (cur+1 >= s.size()) {
            return false;
          }
          int d = (s[cur] - '0') * 10 + (s[cur+1]-'0');
          if (d % B[j] != 0) return false;
          if (j == 0 && i != 0) {
            int nn =  d/B[j];
            if (nn > 9)
              return false;
            A[i] = nn;
          } else if (A[i] != d/B[j]) {
            return false;
          }
          cur+=2;
        } else {
          int d = s[cur] - '0';
          if (j == 0 && i != 0) {
            int nn =  d/B[j];
            if (nn > 9)
              return false;
            A[i] = nn;
          } else if (A[i] != d/B[j]) {
            return false;
          }
          cur++;
        }
      }
    }
    return cur == s.size();
  };
  for (int a=1;a<=9;a++){
    vector<int> B,A;
    if (calc(a, B) && check(a,B,A)) {
      for (int i=0;i<n;i++){
        cout << A[i];
      }
      cout << " ";
      for (int i=0;i<m;i++){
        cout << B[i];
      }
      cout << "\n";
      return;
    }
  }
  cout << "Impossible" << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
