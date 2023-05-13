#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
int side(point s, point e, point p) {
  return sign(cross(p - s, e-s));
}
bool segment_intersect(point s1, point e1, point s2, point e2) {
  if (side(s1, e1, s2) == 0 && side(s1, e1, e2) == 0) {
    return inter(s1.x, e1.x, s2.x, e2.x) && inter(s1.y, e1.y, s2.y, e2.y);
  } else {
    return side(s1, e1, s2) != side(s1, e1, e2) &&
      side(s2,e2,s1) != side(s2,e2,e1);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  while (n--){
    point p1s, p1e, p2s, p2e;
    cin >> p1s.x >> p1s.y >> p1e.x >> p1e.y;
    cin >> p2s.x >> p2s.y >> p2e.x >> p2e.y;
    if (segment_intersect(p1s, p1e, p2s, p2e)) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}
