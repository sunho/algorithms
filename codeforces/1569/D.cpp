#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  const int inf = 1e6+2;
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> bX(n);
  vector<int> bY(m);
  map<int, vector<int>> mX;
  map<int, vector<int>> mY;
  vector<int> aX;
  vector<int> aY;
  for(int i=0;i<n;i++){
    cin >> bX[i];
  }
  for(int i=0;i<m;i++){
    cin >> bY[i];
  }
  vector<pair<int,int>> P;
  for(int i=0;i<k;i++){
    pair<int,int> A;
    cin >> A.x >> A.y;
    P.push_back(A);
    mX[A.x].push_back(A.y);
    mY[A.y].push_back(A.x);
    aX.push_back(A.x);
    aY.push_back(A.y);
  }
  for (auto& [_, arr] : mX) {
    sort(all(arr));
  }
  for (auto& [_, arr] : mY) {
    sort(all(arr));
  }
  sort(all(aX));
  sort(all(aY));
  
  ll ans = 0;
  auto handle = [&](auto& aY, auto& bY, int by, auto& mX, int px, int py) {
    int h = bY[by];
    int l = bY[by-1];
    int ih = lower_bound(all(mX[px]),h) - mX[px].begin();
    int il = upper_bound(all(mX[px]),l) - mX[px].begin();
    ih--;
    int curgroup = ih-il+1;
    int ih2 = lower_bound(all(aY), h) - aY.begin();
    ih2--;
    assert(ih2 >= 0);
    int il2 = upper_bound(all(aY), l) - aY.begin();
    int wg =  ih2-il2+1;
    ans += ih2-il2+1-curgroup;

  };
  for(int i=0;i<k;i++){
    int bx = lower_bound(all(bX),P[i].x) - bX.begin();
    int by = lower_bound(all(bY),P[i].y) - bY.begin();
    int hx = bX[bx];
    int hy = bY[by];
    if (hx == P[i].x && hy == P[i].y) continue;
    if (hx != P[i].x && hy != P[i].y) {
      ans += k-1;
      continue;
    }
    if (hx == P[i].x) {
      handle(aY, bY, by, mX, P[i].x, P[i].y);
    } else {
      handle(aX, bX, bx, mY, P[i].y, P[i].x);
    }
  }
  cout << ans/2 << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}
