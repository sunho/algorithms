#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> A;
  for (int i=0;i<2*n-1;i++){
    int a;
    cin >> a;
    A.push_back(a);
  }
  sort(begin(A),end(A));
  const auto subtract = [&](const vector<int>& A, const vector<int>& B) {
    vector<int> res;
    int ptr = 0;
    for (int i=0;i<A.size();i++){
      if (ptr < B.size() && A[i] == B[ptr]) {
        ptr++;
        continue;
      }
      res.push_back(A[i]);
    }
    return res;
  };
  auto f = [&](auto&& self, int n, vector<int> A) -> vector<int> {
    if (n == 2) {
      int mod0 = -1, mod1 = -1;
      for (int c : A) {
        if (c%2 == 0) {
          if (mod0 == -1) {
            mod0 = c;
          } else {
            return {mod0, c};
          }
        } else {
          if (mod1 == -1) {
            mod1 = c;
          } else {
            return {mod1, c};
          }
        }
      }
    }
    vector<int> id;
    vector<int> sums;
    vector<vector<int>> cand;
    auto work = [&]() {
      auto res = self(self, n/2, A);
      int s = 0;
      A = subtract(A, res);
      for (auto c : res) {
        s += c;
        s %= n;
      }
      id.push_back(id.size());
      cand.push_back(res);
      sums.push_back(s);
    };
    work();
    work();
    work();
    do {
      if ((sums[id[0]] + sums[id[1]]) % n == 0) {
        vector<int> res;
        merge(cand[id[0]].begin(), cand[id[0]].end(), cand[id[1]].begin(), cand[id[1]].end(), back_inserter(res));
        return res;
      }
    } while (std::next_permutation(id.begin(), id.end()));
    assert(false);
  };
  auto res = f(f, n, A);
  for (auto c : res) {
    cout << c << " ";
  }
  cout << "\n";
}
