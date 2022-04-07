const int BM = 2510;
vector<vector<zint>> C(BM+1, vector<zint>(BM+1, 0));
C[0][0] = 1;
for (int n = 1; n <= BM; ++n) {
  C[n][0] = C[n][n] = 1;
  for (int k = 1; k < n; ++k)
    C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
}