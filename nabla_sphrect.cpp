#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

  

void solve() {
  const vec4 denorm_n_z = vec4(-r0.y, r0.x+rectangleExtents.x, r0.y+rectangleExtents.y, -r0.x);
  const vec4 n_z = denorm_n_z*inversesqrt(vec4(r0.z*r0.z)+denorm_n_z*denorm_n_z);
  const vec4 cosGamma = vec4(
      -n_z[0]*n_z[1],
      -n_z[1]*n_z[2],
      -n_z[2]*n_z[3],
      -n_z[3]*n_z[0]
  );
  
  const vec4 g = acos(cosGamma);

  k = 2*nbl_glsl_PI - g[2] - g[3];
  b0 = n_z[0];
  b1 = n_z[2];
  return g[0] + g[1] + g[2] + g[3] - 2*nbl_glsl_PI;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
