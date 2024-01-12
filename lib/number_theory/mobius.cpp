// [gcd(x,y)=1] -> sum_d|gcd(x,y) mobis(d)
vector<int> mobius;
void generate_mobius(int PN) {
  vector<bool> comp(PN+1);
  mobius.assign(PN+1,0);
  mobius[1] = 1;
  for (int i=2; i <= PN; ++i) {
    if (!comp[i]) {
      pr.push_back(i);
      mobius[i] = -1;
    }
    for (int j=0; j < pr.size() && i*pr[j] <= PN; ++j) {
      comp[i*pr[j]] = true;
      if (i % pr[j] == 0) {
        break;
      }
      mobius[i*pr[j]] = mobius[i]*mobius[pr[j]];
    }
  }
}
 
// computes mobius(i) for i from 0 to n in O(nlogn) time
vector<int> mobiussieve(int n) {
  vector<int> m(n+1, -1), p(n+1, 1);
  m[0] = 0, m[1] = 1;
  for (int i = 2; i <= n; i++)
    if (p[i]) for (int j = 2; j*i <= n; j++) {
      if (j%i) m[i*j] = m[i]*m[j];
      else m[i*j] = 0;
      p[i*j] = 0;
    }
  return m;
}

