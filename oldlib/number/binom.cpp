// binomial coefficient
// O(BM^2)
void binom_coeff(int BM, vector<vector<ll>>& C) {
  C.assign(BM+1, vector<ll>(BM+1, 0));
  C[0][0] = 1;
  for (int n = 1; n <= BM; n++) {
    C[n][0] = C[n][n] = 1;
    for (int k = 1; k < n; ++k)
      C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
  }
}