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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<point> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i].x >> A[i].y;
  }
  
  ll ans = 0;
  for (int i=0;i<n;i++) {
    ans += cross(A[i], A[(i+1)%n]);
  }
  cout << abs(ans) << "\n";
}
