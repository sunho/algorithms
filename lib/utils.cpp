// ilog2 gcc/clang
int ilog2(ll x) { return 63 - __builtin_clzll(x); }
int ilog2(int x) { return 31 - __builtin_clz(x); }

// ilog2
int ilog2(int x) {
  int out = 0;
  while (x >>= 1) ++out;
  return out;
}
int ilog2(ll x) {
  int out = 0;
  while (x >>= 1) ++out;
  return out;
}
