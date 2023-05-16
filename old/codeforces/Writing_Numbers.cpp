#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ilog10(ll n) {
  int cnt = 0;
  while(n/=10) cnt++;
  return cnt;
}

ll pow10(int n) {
  ll res = 1;
  while (n--) res *= 10;
  return res;
}

ll f(ll n) {
  string s = to_string(n);
  if (n == 0)
    return 0;
  if (s.size() == 1) {
    return 1;
  }
  ll next = stoll(s.substr(1));
  int lg = ilog10(n);
  ll res = min(n - pow10(lg) + 1, pow10(lg));
  res += f(next);
  res += (s[0]-'0')*f(pow10(lg) - 1);
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  ll n;
  cin >> n;
  ll ok = 0, ng = (ll)1e18+1;
  while (ng - ok > 1) {
    ll mid = (ok+ng)/2;
    if (f(mid) <= n)
      ok = mid;
    else
      ng = mid;
  }
  cout << ok << "\n";
}
