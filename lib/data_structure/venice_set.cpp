struct venice_set {
	multiset<int> S;
	int water_level = 0;
	void insert(int v) {
		S.insert(v + water_level);
	}
	void remove(int v) {
		S.erase(S.find(v + water_level));
	}
	void subtract_all(int v) {
		water_level += v;
	}
	int get_min() {
		return *S.begin() - water_level;
	}
	int size() {
		return S.size();
	}
};
