#include <bits/stdc++.h>
#include <queue>
#include <random>
using namespace std;
using ll = long long;


int f[52][52][51][51];
int g[52][52][26];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  const int inf = 1e9;

  string s,t;
  cin >> s >> t;

  int n = t.size();

  int m;
  cin >> m;
  vector<array<int,2>> ts;
  vector<char> C; 
  vector<string> A;
  for (int i=0;i<m;i++){
    char c; string a;
    cin >> c >> a;
    if (a.size() == 1)
      ts.push_back({c-'a', a[0]-'a'});
    C.push_back(c);
    A.push_back(a);
  }
  m++;
  A.push_back(s);

  for (int i=0;i<=n;i++)
    for (int j=0;j<=n;j++)
      for(int k=0;k<m;k++)
        for (int z=0;z<=A[k].size();z++)
          f[i][j][k][z] = inf;

  for (int i=0;i<=n;i++)
    for (int j=0;j<=n;j++)
      for(int k=0;k<26;k++)
        g[i][j][k] = inf;

  for (int i=0;i<=n;i++){
    for (int j=0;j<m;j++){
      f[i][i][j][0] = 0;
    }
  }

  for (int i=0;i<n;i++){
    g[i][i+1][t[i]-'a'] = 0;
  }
  for (int R=0;R<=n;R++){
    for (int L=R-1;L>=0;L--){
      auto calc = [&]() {
        for (int i=0;i<m;i++){
          for (int j=0;j<A[i].size();j++){
            auto& res = f[L][R][i][j+1];
            for (int M=L;M<R;M++){
              res = min(res, f[L][M][i][j] + g[M][R][A[i][j]-'a']);
            }
            if (j == A[i].size() - 1 && i != m-1) {
              g[L][R][C[i]-'a'] = min(g[L][R][C[i]-'a'], res+1);
            }
          }
        }
      };
      calc();
      for (int k=0;k<26;k++){
        for (auto [a,b] : ts) {
          g[L][R][a] = min(g[L][R][a], g[L][R][b] + 1);
        }
      }
      calc();
    }
  }

  int ans = f[0][n][m-1][s.size()];
  if (ans == inf) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
  }
}
