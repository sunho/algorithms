#include <bits/stdc++.h>

using namespace std;

#define MOD 998244353

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<char>> M(n, vector<char>(m));
  int qs = 0;
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin >> M[i][j];
      if (M[i][j] == '?') {
        qs+=1;
      }
    }
  }
  vector<int> dp(1<<(m-1));
  for (int i=0;i<(1<<(m-1));i++){
    for (int z=0;z<m-1;z++) {
      if (((i >> z) & 1) && (M[0][z] == 'I' || M[0][z] == '?') && (M[0][z+1] == 'C' || M[0][z+1] != '?')) {
        dp[i] = 1;
      }
    }
  }
  for (int i=1;i<n;i++){
    vector<int> next(1<<(m-1));
    for (int j=0;j<(1<<(m-1));j++){
      for (int jj=0;jj<(1<<(m-1));jj++){
        bool skip = false;
        for (int z=0;z<m-1;z++) {
          if (((jj >> z) & 1) && (M[i][z] != 'I' && M[i][z] != '?') && (M[i][z+1] == 'C' && M[i][z+1] != '?')) {
            skip = true;
          }
        }
      }
    }
    dp = move(next);
  }
  int comp = 0;
  for (int j=0;j<N;j++) {
    comp += dp[j];
    comp %= MOD;
  }
  int ans = 1;
  for (int i=0;i<qs;i++){
    ans *= 3;
    ans %= MOD;
  }
  cout << (ans - comp + MOD) % MOD;
  return 0;
} 