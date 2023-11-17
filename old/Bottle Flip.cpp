#include <bits/stdc++.h>

using namespace std;

int main() {
  int h, _, da, dw;
  cin >> h >> _ >> da >> dw;
  auto f = [&](double d) {
    double h1 = h - d;
    double y1 = h - h1/2;
    double y2 = d/2.0;
    return (h1*y1*da + d*y2*dw) / (dw*d+da*h1);
  };
  double l=0.0,r=h;
  for (int k=0;k<10000;k++){
    double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
    if (f(m1) < f(m2)) {
      r = m2;
    } else {
      l = m1;
    }
  }
  cout << setprecision(14) << fixed << r << "\n";
}
