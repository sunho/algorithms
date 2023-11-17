#include <bits/stdc++.h>

using namespace std;

int dd[4] = {-1,0,1};

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<char>> A(n+1, vector<char>(m+1));
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin >> A[i][j];
    }
  }
  for (int i=0;i<=n;i++) {
    A[i][m] = 'X';
  }
  for (int j=0;j<=m;j++) {
    A[n][j] = 'X';
  }
  const int N = 2*n+1;
  const int M = 2*m+1;
  const double inf = 1e9;
  vector<vector<double>> dist(N, vector<double>(M, inf));
  dist[0][0] = 0;
  for (int i=0;i<N;i++){
    for (int j=0;j<M;j++) {
      if (i+1 < N) {
        if (i%2 == 0 || j % 2 == 0) {
          dist[i+1][j] = min(dist[i+1][j], dist[i][j] + 5.0);
        }
      }
      if (j+1 < M) {
        if (j%2 == 0 || i % 2 == 0) {
          dist[i][j+1] = min(dist[i][j+1], dist[i][j] + 5.0);
        }
      }
      if (i+1 < N && j+1 < M) {
        if (A[i/2][j/2] == 'O') {
          if (i%2 == 0 && j % 2 == 1) {
            dist[i+1][j+1] = min(dist[i+1][j+1], dist[i][j] + 10.0*M_PI/4.0);
          }
        }
        if (A[i/2][(j+1)/2] == 'O') {
          if (i%2 == 1 && j % 2 == 0) {
            dist[i+1][j+1] = min(dist[i+1][j+1], dist[i][j] + 10.0*M_PI/4.0);
          }
        }
      }
    }
  }
  cout << fixed << setprecision(15) << dist[N-1][M-1] << "\n";
}
