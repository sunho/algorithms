#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	P perp() const { return P(-y, x); }
};



template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
  auto d = (e1 - s1).cross(e2 - s2);
  if (d == 0) // i f p a r a l l e l
    return {-(s1.cross(e1, s2) == 0), P(0, 0)};
  auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
  return {1, (s1 * p + e1 * q) / d};
}

template<class T>
T polygonArea2(vector<Point<T>>& v) {
  T a = v.back().cross(v[0]);
  for(int i=0;i<v.size()-1;i++) a += v[i].cross(v[i+1]);
  return a;
}

vector<Point<double>> res;
#define DP Point<double>
#define P Point<ll>

void polygonCut(const vector<Point<ll>>& poly, Point<ll> s, Point<ll> e) {
  res.clear();
  for(int i=0;i<poly.size();i++) {
    P cur = poly[i], prv = i ? poly[i-1] : poly.back();
    bool side = s.cross(e, cur) < 0;
    if (side != (s.cross(e, prv) < 0))
      res.push_back(lineInter(DP(s.x,s.y), DP(e.x,e.y), DP(cur.x,cur.y), DP(prv.x,prv.y)).second);
    if (side)
      res.push_back(DP(cur.x,cur.y));
  }
}

inline bool up (P p) {
  return p.y > 0 or (p.y == 0 and p.x >= 0);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  ll n;
  int m;
  cin >> n >> m;
  vector<P> A(m);
  vector<P> rect = {P(0,0), P(n,0), P(n,n), P(0,n)};
  for (int i=0;i<m;i++){
    cin >> A[i].x >> A[i].y;
  }

  double ans = 0.0;
  for (int i=0;i<m;i++){
    P p = A[i];
    vector<pair<P,bool>> B;
    for (int j=0;j<m;j++){
      if (i == j) continue;
      P pt = A[j] - p;
      B.push_back({pt,true});
      B.push_back({pt*-1, false});
    }
    sort(begin(B), end(B), [&](pair<P, bool> a, pair<P, bool> b) -> bool {
      if (up(a.first) != up(b.first)) return up(a.first) < up(b.first);
      if (a.first.cross(b.first) < 0) return true; 
      if (a.first.cross(b.first) > 0) return false;
      return a.second < b.second;
    });
    int pts = 1;
    vector<unordered_set<ll>> vis(n+1);
    for (int j=0;j<2*B.size();j++){
      auto [q, enter] = B[j%B.size()];
      if (enter) {
        pts++;
        if (!vis[p.x+q.x].count(q.y)) {
          vis[p.x+q.x].insert(q.y);
        }
        polygonCut(rect, p+q, p);
        double area = polygonArea2(res)/2.0;
        double cand = (double)pts/m - area/(n*n);
        ans = max(ans, cand);
      } else {
        auto qq = q*-1;
        if (vis[p.x+qq.x].count(qq.y)) {
          vis[p.x+qq.x].erase(qq.y);
          pts--;
        }
      }
    }
  }

  auto go = [&](P a, P b) {
    polygonCut(rect, a, b);
    double area = polygonArea2(res)/2.0;
    return 1.0/m - area/(n*n);
  };
  auto go2 = [&](P a) {
    return max({go(a, P(2*a.x, 0)), go(P(2*a.x, 0), a), go(P(0, 2*a.y), a), go(a, P(0, 2*a.y))});
  };

  for (int i=0;i<m;i++){
    P p = A[i];
    ans = max(ans, go(p, P(p.x,n)));
    ans = max(ans, go(p, P(p.x,0)));
    ans = max(ans, go(p, P(n,p.y)));
    ans = max(ans, go(p, P(0,p.y)));
    ans = max(ans, go(p, P(2*p.x,0)));
    ans = max(ans, go2(P(p.x,p.y)));
    ans = max(ans, go2(P(n-p.x,p.y)));
    ans = max(ans, go2(P(n-p.y,p.x)));
    ans = max(ans, go2(P(n-p.y,n-p.x)));
  }

  cout << fixed << setprecision(10) << ans << "\n";
}

