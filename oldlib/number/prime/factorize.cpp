// sieves + lp
// works when N <= 10^7
// O(n log n) time
void sieves(int PN, vector<ll>& lp, vector<ll>& pr) {
  lp.assign(PN+1,0);
  for (int i=2; i <= PN; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j=0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= PN; ++j) {
      lp[i * pr[j]] = pr[j];
    }
  }
}

// factor one number count p
// O(sqrt(n))
vector<ll> factorize(ll n) {
  vector<ll> facts;
  for (ll d = 2; d * d <= n; d++) {
    while (n % d == 0) {
      facts.push_back(d);
      n /= d;
    }
  }
  if (n > 1)
    facts.push_back(n);
  return facts;
}

// factor one number count p^k
// O(sqrt(n))
vector<pair<ll,int>> factorize(ll n) {
  vector<pair<ll,int>> facts;
  for (ll d = 2; d * d <= n; d++) {
    int k=0;
    while (n % d == 0) {
      n /= d;
      k++;
    }
    if (k != 0) {
      facts.push_back({d,k});
    }
  }
  if (n > 1)
    facts.push_back({n,1});
  return facts;
}

// [gcd(x,y)=1] -> sum_d|gcd(x,y) mobis(d)
void generate_mobius(int PN, vector<int>& mobius, vector<ll>& pr) {
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

