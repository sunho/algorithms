template <typename T>
struct matrix {
  matrix(int n, int m) : n(n), m(m), data(n*m) {}
  matrix(int n) : matrix(n,n) {}
  matrix(initializer_list<initializer_list<T>> l) : matrix(l.size(), m(l.begin()->size()))  {
    int i = 0; for (auto& row : l) copy(row.begin(), row.end(), &data[m * i++]);
  }
  static matrix ones(int n) { matrix res(n); for (int i=0;i<n;i++) res[i][i] = 1; return res; }
  T* operator[](int i) { return &data[m*i]; }
  const T* operator[](int i) const { return &data[m*i]; }
  matrix operator*(const matrix& rhs) {
    assert(m == rhs.n);
    matrix res(n, rhs.m);
    for (int t = 0; t < m; ++t) 
      for (int i = 0; i < n; ++i) 
        for (int j = 0; j < rhs.m; ++j) 
          res[i][j] += (*this)[i][t] * rhs[t][j];
    return res;
  }
  int n,m;
  vector<T> data;
};