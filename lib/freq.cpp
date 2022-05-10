// when number of distinct elements is large
// this is actually faster than hash map or binary map

int maxfreq(vector<int>& a) {
  int res = 0;
  int cur = 0;
  sort(a.begin(), a.end());
  for(int i=0; i < a.size(); i++) {
    if (i == 0 || a[i] == a[i-1]) {
      cur++;
      ckmax(res, cur);
    } else {
      cur = 1;
    }
  }
  return res;
}