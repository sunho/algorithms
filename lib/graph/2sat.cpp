struct two_sat {
  int n;
  vector<int> res;
  sc_components scc;
 
  two_sat(int n) : n(n), scc(2*n) {}
 
  int inv(int v) {
    if (v < n)
      return n + v;
    else
      return v - n;
  }
 
  int norm(int v){
    if (v >= n)
      return v - n;
    return v;
  }
 
  // a or b <=> (~b => a and ~a => b)
  void either(int a, int b) {
    scc.add(inv(a), b);
    scc.add(inv(b), a);
  }
 
  bool run() {
    scc.run();
  
    res.assign(n, -1);
    for (int i=scc.num_comp-1;i>=0;i--){
      for (int a : scc.comps[i]) {
        if (scc.comp_ids[a] == scc.comp_ids[inv(a)]) {
          return false;
        }
        if (res[norm(a)] == -1)
          res[norm(a)] = a < n;
      }
    }
    return true;
  }
};