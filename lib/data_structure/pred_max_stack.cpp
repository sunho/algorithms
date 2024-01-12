template<typename T>
struct pred_max_stack {
  map<int,T> st;
  // return maximum y_i such that x_i <= x
  T query(int x) {
    auto it = st.upper_bound(x);
    if (it == st.begin()) {
      return T();
    }
    return (--it)->second;
  }
  // maintain invariant that x_1 < x_2 < x_3 < ... and y_1 < y_2 < y_3 < ...
  void update(int x, T val) {
    auto it = st.upper_bound(x);
    while (it != st.end() && !(val < it->second)) {
      it = st.erase(it);
    }
    // shouldn't insert when prev y is larger
    if (it != st.begin() && !(prev(it)->second < val)) return;
    st[x] = val;
  }
};

