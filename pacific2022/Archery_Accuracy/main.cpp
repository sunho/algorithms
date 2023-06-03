#include <bits/stdc++.h>
using namespace std;
using ld = double;
using ll = long long;


const ld eps = 1e-9;
int rref(vector<vector<ld>> &a) {
  int n = a.size();
  int m = a[0].size();
  int r = 0;
  for (int c = 0; c < m && r < n; c++) {
    int j = r;
    for (int i = r + 1; i < n; i++)
      if (fabs(a[i][c]) > fabs(a[j][c])) j = i;
    if (fabs(a[j][c]) < eps) continue;
    swap(a[j], a[r]);

    ld s = 1.0 / a[r][c];
    for (int j = 0; j < m; j++) a[r][j] *= s;
    for (int i = 0; i < n; i++) if (i != r) {
      ld t = a[i][c];
      for (int j = 0; j < m; j++) a[i][j] -= t * a[r][j];
    }
    r++;
  }
  return r;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector<ld> p(n);
  for (int i=0;i<n;i++){
    cin >> p[i];
  }
  vector<int> s(n);
  for (int i=0;i<n;i++){
    cin >> s[i];
  }
  auto calc_trans = [&](int from, int to, ld prob) {
    const int m = 2*to+1;
    vector<vector<ld>> trans(m, vector(m+1, 0.0));
    for (int i=0;i<m-1;i++){
      trans[i][i] = 1.0l;
      if (i == 0) continue;
      trans[i][i-1] = -(1.0l-prob);
      trans[i][i+1] = -prob;
    }
    // f(0) = 0
    // 0 = - f(x+1)*(1-p) - f(x-1)*p + f(x)
    // f(m-1) = 1
    trans[m-1][m-1] = 1.0l;
    trans[m-1][m] = 1.0l;
    rref(trans);
    vector<ld> res;
    for (int i=0;i<m;i++){
      res.push_back(trans[i][m]);
    }
    return res;
  };

  vector<vector<vector<ld>>> trans(n, vector<vector<ld>>(n));
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      trans[i][j] = calc_trans(i == 0 ? 0 : s[i-1], s[i], p[j]);
    }
  }
  const int N = 1 << n;
  vector<ld> dp(N);
  dp[0] = 1.0l;
  for (int mask=1;mask<N;mask++){
    int cnt = __builtin_popcount(mask);
    for (int j=0;j<n;j++){
      if (!(mask & (1 << j))) continue;
      int from = cnt == 1 ? 0 : s[cnt-2];
      int to = s[cnt-1];
      int m = 2*to+1;
      ld sum = dp[mask ^ (1<<j)]*trans[cnt-1][j][to+from];
      sum += (1.0l-dp[mask ^ (1<<j)])*trans[cnt-1][j][to-from];
      dp[mask] = max(dp[mask],sum);
    }
  }
  cout << fixed << setprecision(10) << dp[N-1] << "\n";
}
