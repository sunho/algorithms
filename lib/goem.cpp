
struct point {
  ll x, y;
};
point operator+(point a1, point a2) {
  return { a1.x + a2.x, a1.y + a2.y };
}
point operator-(point a1, point a2) {
  return { a1.x - a2.x, a1.y - a2.y };
}
bool operator<(point a1, point a2) {
  if (a1.x < a2.x) return true;
  if (a1.x > a2.x) return false;
  if (a1.y < a2.y) return true;
  return false;
}
ll dot(point p1, point p2) {
	return p1.x * p2.x - p1.y * p2.y;
}
ll cross(point p1, point p2) {
  return p1.x * p2.y - p1.y * p2.x;
}
int sign(ll x) {
  if (x == 0) return 0;
  return x < 0 ? -1 : 1;
}

bool inter(ll l1, ll r1, ll l2, ll r2) {
  if (l1 > r1) swap(l1,r1);
  if (l2 > r2) swap(l2,r2);
  return max(l1,l2) <= min(r1, r2);
}
struct segment {
  point s, e;
};
int side(segment seg, point p) {
  return sign(cross(p - seg.s, seg.e-seg.s));
}
bool segment_intersect(segment a, segment b) {
  if (side(b, a.s) == 0 && side(b, a.e) == 0) {
    return inter(a.s.x, a.e.x, b.s.x, b.e.x) 
      && inter(a.s.y, a.e.y, b.s.y, b.e.y);
  } else {
    return side(b, a.s) != side(b, a.e) 
      && side(a, b.s) != side(a, b.e);
  }
}
bool segment_intersect(segment seg, point p) {
  if (side(seg, p) != 0) return false;
  return inter(seg.s.x, seg.e.x, p.x, p.x) && 
    inter(seg.s.y, seg.e.y, p.y, p.y);
}

int point_in_polygon(const vector<point>& polygon, point p) {
  const int inf = 1e9+1;
  int cnt = 0;
  segment line = {p, {inf, p.y+1}};
  for (int i=0;i<polygon.size();i++){
    segment seg = {polygon[i], polygon[(i+1)%polygon.size()]};
    if (segment_intersect(seg, line)) {
      if (segment_intersect(seg, p)) {
        return 2;
      }
      cnt++;
    }
  }
  return cnt % 2;
}