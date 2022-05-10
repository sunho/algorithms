template <typename F,int N>
struct static_matrix {
  static_matrix() {
    for(auto& a : data) a.fill(0);
  }
  static_matrix(F val) {
    for(auto& a : data) a.fill(0);
    for(int i=0;i<N;i++) data[i][i] = val;
  }

  const array<F,N>& operator[](int i) const {
    return data[i];
  }
  
  array<F,N>& operator[](int i) {
    return data[i];
  }
  
  friend static_matrix<F,N> operator*(const static_matrix<F,N> & lhs, const static_matrix<F,N>& rhs) { 
    static_matrix<F,N> res{};
     for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int t = 0; t < N; ++t) {
          res[i][j] += lhs[i][t] * rhs[t][j];
        }
      }
    }
    return res; 
  }

  friend array<F,N> operator*(const static_matrix<F,N> & lhs, const array<F,N>& rhs) { 
    array<F,N> res;
    res.fill(0);
     for (int i = 0; i < N; ++i) {
      for (int t = 0; t < N; ++t) {
        res[i] += lhs[i][t] * rhs[t];
      }
    }
    return res; 
  }

  static_matrix<F,N>& operator*=(const static_matrix<F,N>& other) {
    *this = *this * other;
    return *this;
  }

  static_matrix<F,N> power(ll b) { 
    static_matrix<F,N> res = static_matrix<F,N>(1);
    static_matrix<F,N> a = *this;
    for (; b; b /= 2, a *= a) { 
      if (b % 2) { res *= a; } 
    } 
    return res; 
  }
  
  static_matrix<F,N>& operator+=(const static_matrix<F,N>& other) {
    for (size_t i = 0; i < N; ++i) {
      for (size_t j = 0; j < N; ++j) {
        (*this)[i][j] *= other[i][j];
      }
    }
    return *this;
  }

  static_matrix<F,N>& operator-=(const static_matrix<F,N>& other) {
    for (size_t i = 0; i < N; ++i) {
      for (size_t j = 0; j < N; ++j) {
        (*this)[i][j] *= other[i][j];
      }
    }
    return *this;
  }

  static_matrix<F,N> transpose() const {
    static_matrix<F,N> out{};
    for (size_t i = 0; i < N; ++i) {
      for (size_t j = 0; j < N; ++j) {
        out[j][i]= (*this)[i][j];
      }
    }
    return out;
  }

  friend static_matrix<F,N> operator+(const static_matrix<F,N> & lhs, const static_matrix<F,N>& rhs) { static_matrix<F,N> res = lhs; res += rhs; return res; }
  friend static_matrix<F,N> operator-(const static_matrix<F,N> & lhs, const static_matrix<F,N>& rhs) { static_matrix<F,N> res = lhs; res -= rhs; return res; }

  array<array<F,N>, N> data;
};

template <typename F>
struct matrix {
  matrix(int n) : n(n) {
    data.assign(n, vector<F>(n));
  }
  matrix(int n, F val) : n(n) {
    data.assign(n, vector<F>(n));
    for(int i=0;i<n;i++) data[i][i] = val;
  }

  vector<F>& operator[](int i) {
    return data[i];
  }

  friend matrix<F> operator*(matrix<F> & lhs, matrix<F>& rhs) { 
    matrix<F> res(lhs.n);
     for (int i = 0; i < lhs.n; ++i) {
      for (int j = 0; j < lhs.n; ++j) {
        for (int t = 0; t < lhs.n; ++t) {
          res[i][j] += lhs[i][t] * rhs[t][j];
        }
      }
    }
    return res; 
  }

  matrix<F> power(matrix<F> a, ll b) { 
    matrix<F> res = matrix<F>(a.n,1);
    for (; b; b /= 2, a *= a) { 
      if (b % 2) { res *= a; } 
    } 
    return res; 
  }
  
  matrix<F>& operator*=(matrix<F>& other) {
    *this = *this * other;
    return *this;
  }

  matrix<F>& operator+=(matrix<F>& other) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        (*this)[i][j] *= other[i][j];
      }
    }
    return *this;
  }

  matrix<F>& operator-=(matrix<F>& other) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        (*this)[i][j] *= other[i][j];
      }
    }
    return *this;
  }

  matrix<F> transpose() const {
    matrix<F> out{};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        out[j][i]= (*this)[i][j];
      }
    }
    return out;
  }

  friend matrix<F> operator+(matrix<F> & lhs, matrix<F>& rhs) { matrix<F> res = lhs; res += rhs; return res; }
  friend matrix<F> operator-(matrix<F> & lhs, matrix<F>& rhs) { matrix<F> res = lhs; res -= rhs; return res; }

  int n;
  vector<vector<F>> data;
};