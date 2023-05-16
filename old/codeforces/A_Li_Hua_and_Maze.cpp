#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n,m;
    cin >> n >> m;
    
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    --x1,--y1,--x2,--y2;
    int ans = 4;
    pair<int,int> cands[] = {{x1-1,y1},{x1+1,y1},{x1,y1-1},{x1,y1+1}};
    int cnt = 0;
    for (auto [x,y] : cands) {
      if (x < 0 || x >= n || y < 0 || y >= m) continue;
      cnt++;
    }
    ans = min(ans,cnt);
    cnt=0;
    pair<int,int> cands2[] = {{x2-1,y2},{x2+1,y2},{x2,y2-1},{x2,y2+1}};
    for (auto [x,y] : cands2) {
      if (x < 0 || x >= n || y < 0 || y >= m) continue;
      cnt++;
    }
    ans = min(ans,cnt);
    cout << ans << "\n";
  }
}
