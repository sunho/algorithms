#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;

int cnt = 0;
int cache[2001][2001];
int cache2[2001][2001];

#define HIDDEN

vector<int> hidden = {4,3, 1, 2, 5};

int query(int l, int r) {
  if (l == r)
    return 0;
  if (cache[l][r] != -1)
    return cache[l][r];
  cnt ++;
  assert(cnt <= 4e4);
  cout << "? " << l + 1 << " " << r + 1 << endl;
  int res;
  cin >> res;
  #ifdef HIDDEN
  int rr = 0;
  for (int i=l;i<=r;i++){
    for (int j=l;j<=i;j++){
      if (hidden[j] > hidden[i]) {
        rr++;
      }
    }
  }
  res = rr%2;
  #endif
  return cache[l][r] = res;
}

bool compare(int i, int j) {
  if (i > j)
    return !compare(j,i);
  if (cache2[i][j] != -1)
    return cache2[i][j];
  if (i == j) {
    return false;
  }
  if (i == j-1) {
    return cache2[i][j] = query(i,j);
  }
  return cache2[i][j] = (query(i, j) - query(i, j-1) - query(i+1, j) + query(i+1, j-1) + 8)%2;
}

int main() {
  memset(cache, -1, sizeof(cache));
  memset(cache2, -1, sizeof(cache2));

  int n;
  cin >> n;

  #ifdef HIDDEN
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  hidden.assign(n,0);
  iota(begin(hidden), end(hidden),0);
  shuffle(begin(hidden), end(hidden), std::default_random_engine(seed));
  #endif

  vector<int> A(n);
  iota(begin(A), end(A), 0);

  vector<vector<ll>> inv(n, vector<ll>(n));

  for (int i=1;i<n;i++) {
    int ng = -1, ok = i;
    while (ok-ng > 1) {
      int m = (ok+ng)/2;
      if (compare(A[i], A[m])) {
        ok = m;
      } else {
        ng = m;
      }
    }
    int tmp = A[i];
    for (int j=i;j>=ok+1;j--){
      A[j] = A[j-1];
    }
    A[ok] = tmp;

    int cnt = 0;
    for (int j=i-1;j>=0;j--) {
      if (A[j] > tmp) 
        cnt ++;
      inv[A[j]][i] = inv[A[j]][i-1] + cnt;
      if (A[j] < tmp) {
        cache[A[j]][tmp] = (inv[A[j]][i] % 2)^1;
      } else {
        cache[tmp][A[j]] = (inv[A[j]][i] % 2);
      }
    }
  }
  reverse(begin(A), end(A));
  vector<int> ans(n);
  for (int i=0;i<n;i++) ans[A[i]] = i;
  cout << "! ";
  for (int i=0;i<n;i++){
    cout << ans[i] + 1 << " ";
  }
  cout << endl;
  #ifdef HIDDEN
  assert(ans == hidden);
  #endif
}

// 2 1

// 3 1 2
// 