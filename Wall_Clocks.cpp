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

bool intersect(pair<int,int> a, pair<int,int> b, int T) {
  auto [s,t] = a;
  auto [s2,t2] = b;
  if (s > t) {
    swap(s,t);
    return intersect(b, {0, s}, T) || intersect(b, {t, T}, T);
  }
  return max(s,s2) <= min(t,t2);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n,w,h;
  cin >> n >> w >> h;

  auto gen_cands_pos = [&](point p) {
    vector<pair<int,int>> res;
    res.push_back({0,p.y-p.x});
    res.push_back({p.x-p.y,0});
    res.push_back({w,p.y-p.x+w});
    res.push_back({p.x-p.y+h,h});
    return res;
  };
  auto gen_cands_neg = [&](point p) {
    vector<pair<int,int>> res;
    res.push_back({0,p.y+p.x});
    res.push_back({p.x+p.y,0});
    res.push_back({w,p.y+p.x-w});
    res.push_back({p.x+p.y-h,h});
    return res;
  };
  auto convert_to_time = [&](point p) {
    if (p.y == 0) {
      return p.x;
    }
    if (p.x == w) {
      return p.x+p.y;
    }
    if (p.y == h) {
      return w+h+(w-p.x);
    }
    return w + h + w + (h-p.y);
  };
  auto get_hit = [&](const vector<pair<int,int>>& cands) {
    for (auto [x,y] : cands) {
      if (x >= 0 && x <= w && y >= 0 && y <= h) {
        return convert_to_time({x,y});
      }
    }
    assert(false);
    exit(1);
  };
  vector<pair<int,int>> intervals(n);

  for (int i=0;i<n;i++){
    point p;
    cin >> p.x >> p.y;
    char dir;
    cin >> dir;
    auto pos = gen_cands_pos(p), neg = gen_cands_neg(p);
    switch (dir) {
    case 'W':
      intervals[i] = {get_hit({neg[0], neg[3]}), get_hit({pos[0],pos[1]})};
      break;
    case 'E':
      intervals[i] = {get_hit({neg[2], neg[1]}), get_hit({pos[2],pos[3]})};
      break;
    case 'N':
      intervals[i] = {get_hit({pos[3],pos[2]}), get_hit({neg[3], neg[0]})};
      break;
    case 'S':
      intervals[i] = {get_hit({pos[1],pos[0]}), get_hit({neg[1], neg[2]})};
      break;
    }
  }
  int ans = 1e9;
  const int T = 2*w+h*2;
  for (int i=0;i<n;i++){
    vector<pair<int,int>> worklist;
    int st = intervals[i].first;
    int en = intervals[i].second;
    for (int j=0;j<n;j++){
      auto [s,t] = intervals[j];
      int ns = (s-st+T)%T, nt = (t-st+T)%T;
      if (ns <= nt) {
        worklist.push_back({ns,nt});
      } else {
        worklist.push_back({ns, T});
      }
    }
    int cnt = 0;
    int q = -1;
    sort(begin(worklist), end(worklist));
    for (int j=0;j<worklist.size();j++){
      auto [l,r] = worklist[j];
      if (l <= q) {
        q = min(q, r);
      } else {
        cnt++;
        q = r;
      }
    }
    ans = min(ans, cnt);
  }
  cout << ans << "\n";
}
