// extended gcd
// can be used to calculate modular inverse
tuple<ll,ll,ll> exgcd(ll a, ll b) {
  ll x = 1, y = 0;
  ll x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    ll q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return {a1,x,y};
}

// Chinease remainder theorem
ll normalize(ll x, ll mod) { x %= mod; if (x < 0) x += mod; return x; }
template<typename T>
ll do_crt(vector<T>& a, vector<T>& m) {
  ll ans = a[0];
  ll l = m[0];
  for(int i = 1; i < a.size(); i++) {
    auto [d, x1, y1] = exgcd(l, m[i]);
    if((a[i] - ans) % d != 0) {
      return -1;
    }
    ans = normalize(ans + x1 * (a[i] - ans) / d % (m[i] / d) * l, l * m[i] / d);
    l = lcm(l, m[i]);
  }
  return ans;
}

