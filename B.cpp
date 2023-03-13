#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

struct Point
{
    int x;
    int y;
};

bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
 
    return false;
}

int orientation(Point p, Point q, Point r)
{
    ll val = (ll)(q.y - p.y) * (r.x - q.x) -
              (ll)(q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;
 
    return (val > 0)? 1: 2;
}
 
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;
 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false;
}
void solve() {
  int n;
  cin >> n;
  vector<pair<Point,Point>> P;
  vector<int> ws;
  for(int i=0;i<n;i++){
    int x1,y1,x2,y2,w;
    cin >> x1 >> y1 >> x2 >> y2 >> w;
    P.push_back({{x1,y1},{x2,y2}});
    ws.push_back(w);
  }
  vector<set<int>> g(n);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if (doIntersect(P[i].first, P[i].second, P[j].first, P[j].second)) {
        g[i].insert(j);
      }
    }
  }
  set<int> rem;
  for(int i=0;i<n;i++){
    rem.insert(i);
  }
  ll ans = 0;
  while(!rem.empty()) {
    pair<ll, int> mini = {(ll)1e18, 0};
    for (int i : rem) {
      mini = min(mini, {(ll)ws[i]*g[i].size(), i});
    }
    ans += mini.first;
    for(int j : g[mini.second]) {
      g[j].erase(mini.second);
    }
    rem.erase(mini.second);
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
