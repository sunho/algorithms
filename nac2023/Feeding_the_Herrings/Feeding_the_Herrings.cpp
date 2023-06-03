#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 12'345'647;

void solve(string s, string l) {
  vector<int> S;
  int n = s.size();
  int m = l.size();
  vector<int> A, B;
  for (int i=0;i<n;i++) A.push_back(s[i]-'0');
  for (int i=0;i<m;i++) B.push_back(l[i]-'0');
  reverse(begin(A), end(A));
  reverse(begin(B), end(B));
  for (int i=m;i<n;i++) B.push_back(0);
  int dp[3][2][2][2];
  memset(dp, 0, sizeof dp);
  dp[0][1][1][1] = 1;
  for (int i=0;i<n;i++) {
    int next[3][2][2][2];
    memset(next, 0, sizeof next);
    for (int c=0;c<3;c++) {
      for (int h1=0;h1<2;h1++) for (int h2=0;h2<2;h2++) for(int h3=0;h3<2;h3++)
        for (int x=0;x<=9;x++){
          if (x == 3) continue;
          for (int y=0;y<=9;y++) {
            if (y == 3) continue;
            int z = A[i] - x - y - c;
            z = (z + 50)%10;
            if (z == 3) continue;
            int nh1 = B[i] < x ? 1 : 0;
            int nh2 = B[i] < y ? 1 : 0;
            int nh3 =  B[i] < z ? 1 : 0;
            if (B[i] == x) nh1 = h1;
            if (B[i] == y) nh2 = h2;
            if (B[i] == z) nh3 = h3;
            // if (i == 1 && nh1 == 1 && nh2 == 1 && nh3 == 1) {
            //   cout << x << " " << y << " " << z << " " <<  dp[c][h1][h2][h3] << "\n";
            // }
            int nc = 0;
            if (x+y+z+c>=20) nc = 2;
            else if (x+y+z+c>=10) nc = 1;
            next[nc][nh1][nh2][nh3] = (next[nc][nh1][nh2][nh3] + dp[c][h1][h2][h3]) % MOD;
          }
        }
    }
    memcpy(dp, next, sizeof dp);
  }
  cout << dp[0][1][1][1] << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s,l;
  while (true) {
    cin >> s >> l;
    if (s == "0" && l == "0") break;
    solve(s,l);
  }

}
